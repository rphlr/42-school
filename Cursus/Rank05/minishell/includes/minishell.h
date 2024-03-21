/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:28:03 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/31 16:33:39 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ---------<<INCLUDES>>--------- */
// Librairies
# include "../mylib/includes/mylib.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <termios.h>
# include <dirent.h>

/* ---------<<MACROS>>--------- */
// Colors definition
# define C_RED "\033[0;31m"
# define C_GREEN "\033[0;32m"
# define C_YELLOW "\033[0;33m"
# define C_BLUE "\033[0;34m"
# define C_MAGENTA "\033[0;35m"
# define C_CYAN "\033[0;36m"
# define C_BLACK "\033[30m"
# define C_WHITE "\033[37m"
# define C_RESET "\033[0m"

// Text effects definition
# define C_BOLD "\033[1m"
# define C_UNDERLINE "\033[4m"
# define C_BLINK "\033[5m"
# define C_REVERSE "\033[7m"
# define C_INVISIBLE "\033[8m"
# define C_STRIKETHROUGH "\033[9m"
# define C_CLEAR "\033[2J\033[1;1H"

// Background colors definition
# define C_BBLACK "\033[40m"
# define C_BWHITE "\033[47m"
# define C_BRED "\033[41m"
# define C_BGREEN "\033[42m"
# define C_BYELLOW "\033[43m"
# define C_BBLUE "\033[44m"
# define C_BMAGENTA "\033[45m"
# define C_BCYAN "\033[46m"

// Create  prompt
# define PROMPT "\033[1m\033[7m\033[4m\033[41m Les pros du HTML >\033[0m "

// Define ee
# define MS_1 "███    ███ ██ ███    ██ ██ █████ ██  ██ ███████ ██     ██\n"
# define MS_2 "████  ████ ██ ████   ██ ██ ██    ██  ██ ██      ██     ██\n"
# define MS_3 "██ ████ ██ ██ ██ ██  ██ ██ █████ ██████ █████   ██     ██\n"
# define MS_4 "██  ██  ██ ██ ██  ██ ██ ██    ██ ██  ██ ██      ██     ██\n"
# define MS_5 "██      ██ ██ ██   ████ ██ █████ ██  ██ ███████ ██████ ██████\n"

// Define errors print
# define ERR_QUOTE "minishell: quote error\n"
# define ERR_DQUOTE "minishell: dquote error\n"
# define ERR_PARSE "minishell: syntax error near unexpected token `%s'\n"
# define ERR_OPTION "option error `%s'\n"
# define ERR_CD "minishell: cd: %s: %s\n"
# define ERR_CD_HOME "minishell: cd: HOME not set\n"

# define SHLVL "You are currently using %s level%s of our minishell.\n"

int	g_current_state;

/* ---------<<STRUCTURES>>--------- */
typedef enum s_shell_state
{
	STATE_NORMAL,
	STATE_HEREDOC,
	STATE_BLOCKING_CMD
}						t_shell_state;

// Types of tokens
typedef enum s_token
{
	WORD,
	PIPE,
	INPUT,
	OUTPUT,
	APPEND,
	HEREDOC,
	AND,
	OR,
	SEMICOLON,
	CLOSED_QUOTE,
	CLOSED_DQUOTE,
	NOT_CLOSED_QUOTE,
	NOT_CLOSED_DQUOTE,
	OPTIONS,
	STAR,
	DOLLAR,
	TILDE,
	COLON,
	IGNORE,
	BS_NEWLINE,
	BS_TAB,
	BS_VERTICAL_TAB,
	BS_BACKSPACE,
	BS_CARRIAGE_RETURN,
	BS_FORM_FEED,
	BS_BELL,
	BS_ESCAPE,
	BS_BACKSLASH,
	END
}						t_token;

// State of the parsing
typedef enum state
{
	VALID,
	QUOTE_ERROR,
	DQUOTE_ERROR,
	PIPE_ERROR,
	INPUT_ERROR,
	OUTPUT_ERROR,
	APPEND_ERROR,
	HEREDOC_ERROR,
	AND_ERROR,
	OR_ERROR,
	SEMICOLON_ERROR,
	OPTIONS_ERROR
}						t_state;

// Types of redirections
typedef enum s_redirectiontype
{
	NO_REDIRECTION,
	INPUT_REDIRECTION,
	OUTPUT_REDIRECTION,
	APPEND_REDIRECTION,
	HEREDOC_REDIRECTION
}						t_redirectiontype;

// Options for echo
typedef enum s_option
{
	NO_OPTION,
	OPTION_N,
	INVALID_OPTION
}						t_option;

// History
typedef struct s_history
{
	char				*line;
	struct s_history	*next;
}	t_history;

// Redirections and heredocs
typedef struct s_redirection
{
	t_redirectiontype	type;
	char				*filename;
	char				*limiter;
	int					type_hd;
}						t_redirection;

// Environment variables
typedef struct s_env
{
	char				*name;
	char				*value;
	struct s_env		*next;
}						t_env;

// Commands
typedef struct s_cmds
{
	char				*cmd;
	t_redirection		*redir;
	struct s_cmds		*next;
}						t_cmds;

// Count tokens
typedef struct s_count
{
	int					nbr_tokens;
	int					nbr_cmds;
	int					nbr_pipes;
	int					nbr_inputs;
	int					nbr_outputs;
	int					nbr_appends;
	int					nbr_heredocs;
	int					nbr_colons;
	int					nbr_semicolons;
	int					nbr_ands;
	int					nbr_ors;
	int					nbr_options;
	bool				special_cases;
}						t_count;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

// Line
typedef struct s_line
{
	char				**token;
	t_token				*type;
	t_cmds				*cmds;
	bool				pipe;
	bool				heredoc;
	t_count				*count;
}						t_line;

// Global structure
typedef struct s_global
{
	int					exit_code;
	char				*home_folder;
	t_env				*env;
	t_line				*line;
}						t_global;

// Format structure
typedef struct s_format
{
	t_token				*new_types;
	char				**new_tokens;
	int					*token_idx;
	int					original_count;
	int					entries_count;
	int					in_double_quotes;
	int					in_simple_quotes;
	char				*output;
	int					i;
}						t_format;

/* ---------<<PROTOTYPES>>--------- */
// Main
int						lsh_loop(t_global *global);
int						line_is_wspaces(char *line);
void					add_to_history_list(t_history **head, char *line);
char					*rm_newline(char *line);
int						line_does_not_exist(t_global *global, char *line);
int						command_empty(t_global *global);

// Builtins
void					ft_echo(char *cmd, t_global *global);
char					**env_list_to_array(t_env *env_list);
char					*get_env_value(char *name, t_env *env);
void					ft_env(t_global *global);
void					ft_pwd(t_line *line);
void					add_env_node(t_env **new_head, t_env **new_current,
							t_env *node);
t_env					*clone_env_node(t_env *src);
t_env					*new_env_item(char *name, char *value);
t_env					*clone_env_list(t_env *head);
void					extract_name_value(char *token, char **name,
							char **value);
void					sorting_env(t_env *env_cpy);
void					ft_export(t_global *global, t_line *line);
void					ft_cd(char *cmd, t_global *global);
void					ft_unset(t_global *global, t_line *line);
bool					check_exit_token(char *arg);
void					ft_exit(t_global *global);
void					ft_easter_egg(void);
void					ft_mslvl_see(t_env *env);

// Parsing
t_state					check_token_errors(t_token *type, char **tokens,
							t_state *error_table);
bool					check_token(char *line);
t_state					check_errors(t_token *type, char **tokens,
							t_global *global);
char					*epur_str(char *line);
t_global				*parse_cmd(t_global *global);
t_count					*count_types(t_token *type);
t_state					ft_error(t_token *type, char **tokens,
							t_global *global);
t_cmds					*init_cmds(char **tokens, t_token *type);
t_line					*init_line(char *line, t_global *global);
t_global				*init_global(char **envp);
char					*format_options(char *token);
char					**parsed_line(char *line);
t_env					*init_env(char **envp);
t_token					*init_tokens_type(char **tokens);
void					set_filename(t_cmds *head, char **tokens,
							t_token *type, int *i);
void					handle_token(t_cmds *head, char **tokens,
							t_token *type, int *i);
int						open_directory(DIR **dir);
int						count_quotes_in_token(char *token);
int						count_new_tokens(char *token);
int						count_total_tokens(char **tokens);
char					**split_tokens_with_multiple_quotes(char **tokens);
void					handle_star_token(t_global *global, int *token_idx,
							int *type_idx, int original_count);
void					handle_input_error(char **tokens);
void					handle_output_error(char **tokens);
void					handle_append_error(char **tokens);
void					handle_heredoc_error(char **tokens);
void					handle_and_error(char **tokens);
t_token					*process_token(t_token *type, t_count *count);
int						count_substrings(char *line);
char					*extract_variable_name(char *ptoken);
int						biggest_var_value(t_env	*env);

t_token					handle_pipe(char *token);
t_token					handle_input_redirect(char *token);
t_token					handle_output_redirect(char *token);
t_token					handle_dash(char *token);
void					handle_dollar(char **token, t_global *global,
							t_format *fmt);
int						is_quotes(char c, int *in_double_quotes,
							int *in_simple_quotes);
void					init_format(t_format *fmt, t_global *global);

// Execution
//void					init_history(char *line, t_history *history_head,
//							int history_fd);
// char					*ft_remove_char(char *str, char c);

// *---* exec *---*
void					close_and_wait(int **fds, int num_cmds);
char					**env_to_char(t_global *global);
char					*get_path(char *command, char **paths);
void					ft_heredoc(char *filename, char *limiter, int type);
pid_t					manage_pid(pid_t *new_pid);
int						manage_exit(int *new_code);
void					run_cmd(t_global *global);
int						cmd_is_primaries(char *cmd);
void					execute_primaries(char	*cmd, t_global *global);
void					execute_specials(t_global *global);
int						execute_cmd(char *cmd, t_redirection *redir,
							t_global *global);
void					ft_redir(t_global *global, t_cmds *curr_cmd);
void					ft_or(t_global *global, t_cmds *curr_cmd,
							t_cmds *next_cmd);
void					ft_and(t_global *global, t_cmds *curr_cmd,
							t_cmds *next_cmd);
void					execute_pipeline(t_global *global, t_cmds *cmds);
void					ft_pipe(t_global *global, t_cmds *curr_cmd,
							t_cmds *next_cmd);
char					*found_command(t_global *global, char **paths,
							char *argv[]);
void					is_filename(char *filename, int type);
void					handle_redirection(char *filename, int type);
int						open_and_check(char *filename, int flags);
void					process_heredoc(char *limiter);
void					create_heredoc_file(void);
void					fill_argv(char *cmd, char **argv, t_global *global);
int						handle_redirections(t_redirection *redir,
							t_global *global);
int						pid_creation(t_global *global, char	**paths,
							char *argv[], t_redirection *redir);
int						check_state(pid_t pid, int status);
void					create_file(int fd, t_redirection *redir,
							t_global *global);
void					ft_semicolon(t_global *global, t_cmds *curr_cmd,
							t_cmds *next_cmd);
int						checking_primaries(t_global *global, int primaries);
void					execute_pipeline(t_global *global, t_cmds *cmds);
int						count_cmds(t_cmds *cmds);
t_env					*find_or_create_mslvl(t_env *head);
void					initialize_pipes(int **fds, int num_cmds,
							t_global *global);
void					dup_and_close(int **fds, int i, int num_cmds);
void					check_first_pid(pid_t pid, int fds[2], t_cmds *curr_cmd,
							t_global *global);
void					check_second_pid(pid_t pid2, int fds[2],
							t_cmds *next_cmd, t_global *global);
int						check_or(t_count *count_tmp, t_global *global,
							t_cmds *curr_cmd, t_token *type_tmp);
int						check_and(t_count *count_tmp, t_global *global,
							t_cmds *curr_cmd, t_token *type_tmp);
int						check_semicolon_and_pipe(t_count *count_tmp,
							t_global *global, t_cmds *curr_cmd,
							t_token *type_tmp);
int						check_special(t_count *count_tmp, t_global *global,
							t_cmds *curr_cmd,
							t_token *type_tmp);
void					call_checks(t_count *count_tmp, t_global *global,
							t_cmds *curr_cmd, t_token *type_tmp);
char					*get_next_color(void);

// Signals
void					ft_signal(void);
void					sigint_manage(int num);
void					set_termios(void);

#endif
