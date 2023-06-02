# 42-born2beroot

<p align="center">This is an overview of how I completed my "Born2beroot" project.</p>

<p align="center">
	<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/rphlr/42-born2beroot?color=green&logo=github&logoColor=green&style=flat-square">
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/rphlr/42-born2beroot?color=green&logo=github&logoColor=green&style=flat-square">
</p> 

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

# 💡 About the project

> _This project aims to help you discover the wonderful world of virtualization._

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

# Table of Contents
1. [**Installation step**](#installation)
	* [How to proceed](#how-to-proceed)
		* [First steps](#first-steps)
		* [ISO file installation](#iso-file-installation)
		* [VM installation](#start-the-vm)
		* [Let us proceed with the creation of the partitions](#let-us-proceed-with-the-creation-of-the-partitions)
2. [**sudo**](#sudo)
	* [Step 1: Installing *sudo*](#step-1-installing-sudo)
	* [Step 2: Adding User to *sudo* Group](#step-2-adding-user-to-sudo-group)
	* [Step 3: Executing commands with superuser privileges](#step-3-executing-commands-with-superuser-privileges)
	* [Step 4: Configuring *sudo*](#step-4-configuring-sudo)
3. [**SSH**](#ssh)
	* [Step 1: Installation and configuration of SSH](#step-1-installation-and-configuration-of-ssh)
	* [Step 2: Installation and configuration of UFW](#step-2-installation-and-configuration-of-ufw)
	* [Step 3: Connecting to the server using SSH](#step-3-connecting-to-the-server-using-ssh)
4. [**User Management**](#user-management)
	* [Step 1: Establishing a robust Password Policy](#step-1-establishing-a-robust-password-policy)
	   * [Password Age](#password-age)
	   * [Password Strength](#password-strength)
	* [Step 2: Creating a new user account](#step-2-creating-a-new-user-account)
	* [Step 3: Creating a new user group](#step-3-creating-a-new-user-group)
5. [**cron**](#cron)
	* [Configuring a *cron* Job](#configuring-a-cron-job)
6. [**Bonus**](#bonus)
	* [#1: Installation and Configuration of the Linux Lighttpd MariaDB PHP *(LLMP)* Stack](#1-installation-and-configuration-of-the-linux-lighttpd-mariadb-php-llmp-stack)
	   * [Step 1: Installation of Lighttpd](#step-1-installation-of-lighttpd)
	   * [Step 2: Installation & Configuration of MariaDB](#step-2-installation-and-configuration-of-mariadb)
	   * [Step 3: Installation of PHP](#step-3-installation-of-php)
	   * [Step 4: Downloading and configuring WordPress](#step-4-downloading-and-configuring-wordpress)
	   * [Step 5: Configuration of Lighttpd](#step-5-configuration-of-lighttpd)
	* [#2: File Transfer Protocol *(FTP)*](#2-file-transfer-protocol-ftp)
	   * [Step 1: Installation and configuration of FTP](#step-1-installation-and-configuration-of-ftp)
	   * [Step 2: Etablishing an FTP connection to the server](#step-2-establishing-an-ftp-connection-to-the-server)
	* [#3: Fail2ban (Just because I would like to implement it as an additional security measure, in addition to FTP)](#3-fail2ban-just-because-i-would-like-to-implement-it-as-an-additional-security-measure-in-addition-to-ftp))
7. [**Evaluation**](#evaluation)
	* [General instructions](#general-instructions)
		* [Signature file](#signature-file)
	* [Mandatory part](#mandatory-part)
		* [How does a virtual machine work?](#how-does-a-virtual-machine-work)
		* [Why Debian rather than Rocky?](#why-debian-rather-than-rocky)
		* [Basic differences between Rocky and Debian?](#basic-differences-between-rocky-and-debian)
		* [The benefits of virtual machines](#the-benefits-of-virtual-machines)
		* [The difference between apt and aptitude](#the-difference-between-apt-and-aptitude)
		* [What is AppArmor?](#what-is-apparmor)
	* [Simple setup](#simple-setup)
		* [Check if UFW is started](#check-if-ufw-is-started)
		* [Check if SSH is started](#check-if-ssh-is-started)
	* [**User**](#user)
		* [Check if user is in the sudo and user42 group](#check-if-user-is-in-the-sudo-and-the-user42-group)
		* [Add a new user](#add-a-new-user)
		* [Create the `evaluating` group](#create-the-evaluating-group)
		* [Add user to the group](#add-user-to-the-group)
		* [Advantages and disadvantages of this password policy](#advantages-and-disadvantages-of-this-password-policy)
	* [Hostname and partitions](#hostname-and-partitions)
		* [Change the hostname](#change-the-hostname)
		* [Check partitions](#check-partitions)
		* [What is LVM and what it is all about ?](#what-is-lvm-and-what-it-is-all-about)
	* [sudo](#sudo-1)
		* [Check if sudo is properly installed](#check-if-sudo-is-properly-installed)
		* [Assign an user to sudo group](#assign-an-user-to-sudo-group)
		* [Check sudo settings](#check-sudo-settings)
			* [*Strict rules*](#strict-rules)
			* [*Verify the logs*](#verify-the-logs)
	* [UFW / Firewall](#ufw--firewall)
		* [Check UFW status and ports](#check-ufw-status-and-ports)
			* [*Add a new rule*](#add-a-new-rule)
			* [*Delete a rule*](#delete-a-rule)
	* [SSH](#ssh-1)
		* [Check SSH status](#check-ssh-status)
		* [List open SSH ports](#list-open-ssh-ports)
	* [Script](#script)
		* [Script explication](#script-explication)
		* [What "cron" is ?](#what-is-cron)
	* [Bonus](#bonus-1)
		* [WordPress site](#wordpress-site)
		* [FTP service](#ftp-service)
		* [Fail2ban](#fail2ban)

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

# **Installation**

As of the time of writing, the most recent stable release of [Debian](https://www.debian.org) is version 11 *Bullseye*.
To obtain the latest *netinst* Debian image, which contains only the essential Debian installer code and a minimal selection of text-mode programs, please visit this link: https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/.

## How to proceed

In addition, I have also completed the bonus sections.

### First steps

To begin, we shall create a new virtual machine.
![how-to-proceed_image](how-to-proceed_images/0001.png)

Install it in your directory in "sgoinfre" to have access to it on any computer at school, or in "goinfre" for local installation, which is significantly faster.
![how-to-proceed_image](how-to-proceed_images/0002.png)

Leave the memory size as the default setting.
![how-to-proceed_image](how-to-proceed_images/0003.png)

Next, we will create a virtual hard disk.
![how-to-proceed_image](how-to-proceed_images/0004.png)

Select "VirtualBox Disk Image" from the available options.
![how-to-proceed_image](how-to-proceed_images/0005.png)

Select "Dynamically allocated" as the allocation type.
![how-to-proceed_image](how-to-proceed_images/0006.png)

Select the desired size for your virtual machine, and proceed to create it.
![how-to-proceed_image](how-to-proceed_images/0007.png)

Click on the "Settings" button.
![how-to-proceed_image](how-to-proceed_images/0008.png)

### ISO file installation

Next, select the "Storage" option.
![how-to-proceed_image](how-to-proceed_images/0009.png)

Select the empty controller, then choose the disk icon and follow the subsequent steps.
![how-to-proceed_image](how-to-proceed_images/0010.png)

![how-to-proceed_image](how-to-proceed_images/0011.png)

![how-to-proceed_image](how-to-proceed_images/0012.png)

![how-to-proceed_image](how-to-proceed_images/0013.png)

![how-to-proceed_image](how-to-proceed_images/0014.png)

### Start the VM

![how-to-proceed_image](how-to-proceed_images/0015.png)

![how-to-proceed_image](how-to-proceed_images/0016.png)

You can scale the windows to make it slightly larger.
![how-to-proceed_image](how-to-proceed_images/0017.png)

Follow these steps to install the bonuses (if you have any questions about how to proceed, please do not hesitate to contact me at rrouille@student.42lausanne.ch).
![how-to-proceed_image](how-to-proceed_images/0018.png)

![how-to-proceed_image](how-to-proceed_images/0019.png)

![how-to-proceed_image](how-to-proceed_images/0020.png)

![how-to-proceed_image](how-to-proceed_images/0021.png)

![how-to-proceed_image](how-to-proceed_images/0022.png)

![how-to-proceed_image](how-to-proceed_images/0023.png)

![how-to-proceed_image](how-to-proceed_images/0024.png)

![how-to-proceed_image](how-to-proceed_images/0025.png)

![how-to-proceed_image](how-to-proceed_images/0026.png)

![how-to-proceed_image](how-to-proceed_images/0027.png)

![how-to-proceed_image](how-to-proceed_images/0028.png)

![how-to-proceed_image](how-to-proceed_images/0029.png)

![how-to-proceed_image](how-to-proceed_images/0030.png)

### Let us proceed with the creation of the partitions

Note that the size may vary.

#### *The first partition is the primary one.*

![how-to-proceed_image](how-to-proceed_images/0031.png)

![how-to-proceed_image](how-to-proceed_images/0032.png)

![how-to-proceed_image](how-to-proceed_images/0033.png)

![how-to-proceed_image](how-to-proceed_images/0034.png)

![how-to-proceed_image](how-to-proceed_images/0035.png)

![how-to-proceed_image](how-to-proceed_images/0036.png)

![how-to-proceed_image](how-to-proceed_images/0037.png)

![how-to-proceed_image](how-to-proceed_images/0038.png)

Make sure to mount it as the boot partition.

![how-to-proceed_image](how-to-proceed_images/0039.png)

![how-to-proceed_image](how-to-proceed_images/0040.png)

![how-to-proceed_image](how-to-proceed_images/0041.png)

#### *The others partitions*

![how-to-proceed_image](how-to-proceed_images/0042.png)

![how-to-proceed_image](how-to-proceed_images/0043.png)

![how-to-proceed_image](how-to-proceed_images/0044.png)

![how-to-proceed_image](how-to-proceed_images/0045.png)

![how-to-proceed_image](how-to-proceed_images/0046.png)

![how-to-proceed_image](how-to-proceed_images/0047.png)

![how-to-proceed_image](how-to-proceed_images/0048.png)

Encrypt the disk for added security.

![how-to-proceed_image](how-to-proceed_images/0049.png)

![how-to-proceed_image](how-to-proceed_images/0050.png)

![how-to-proceed_image](how-to-proceed_images/0051.png)

![how-to-proceed_image](how-to-proceed_images/0052.png)

![how-to-proceed_image](how-to-proceed_images/0052a.png)

![how-to-proceed_image](how-to-proceed_images/0053.png)

![how-to-proceed_image](how-to-proceed_images/0054.png)

![how-to-proceed_image](how-to-proceed_images/0055.png)

![how-to-proceed_image](how-to-proceed_images/0056.png)

![how-to-proceed_image](how-to-proceed_images/0057.png)

![how-to-proceed_image](how-to-proceed_images/0058.png)

![how-to-proceed_image](how-to-proceed_images/0059.png)

![how-to-proceed_image](how-to-proceed_images/0060.png)

![how-to-proceed_image](how-to-proceed_images/0061.png)

![how-to-proceed_image](how-to-proceed_images/0062.png)

![how-to-proceed_image](how-to-proceed_images/0063.png)

![how-to-proceed_image](how-to-proceed_images/0064.png)

![how-to-proceed_image](how-to-proceed_images/0065.png)

![how-to-proceed_image](how-to-proceed_images/0066.png)

![how-to-proceed_image](how-to-proceed_images/0067.png)

![how-to-proceed_image](how-to-proceed_images/0068.png)

![how-to-proceed_image](how-to-proceed_images/0069.png)

![how-to-proceed_image](how-to-proceed_images/0070.png)

![how-to-proceed_image](how-to-proceed_images/0071.png)

![how-to-proceed_image](how-to-proceed_images/0072.png)

![how-to-proceed_image](how-to-proceed_images/0073.png)

![how-to-proceed_image](how-to-proceed_images/0074.png)

![how-to-proceed_image](how-to-proceed_images/0075.png)

![how-to-proceed_image](how-to-proceed_images/0076.png)

![how-to-proceed_image](how-to-proceed_images/0077.png)

![how-to-proceed_image](how-to-proceed_images/0078.png)

![how-to-proceed_image](how-to-proceed_images/0079.png)

![how-to-proceed_image](how-to-proceed_images/0080.png)

![how-to-proceed_image](how-to-proceed_images/0081.png)

![how-to-proceed_image](how-to-proceed_images/0082.png)

![how-to-proceed_image](how-to-proceed_images/0083.png)

![how-to-proceed_image](how-to-proceed_images/0084.png)

![how-to-proceed_image](how-to-proceed_images/0085.png)

![how-to-proceed_image](how-to-proceed_images/0086.png)

Here's a trick for the "var--log" partition: use only one hyphen, as it will be automatically doubled.

![how-to-proceed_image](how-to-proceed_images/0087.png)

![how-to-proceed_image](how-to-proceed_images/0088.png)

![how-to-proceed_image](how-to-proceed_images/0089.png)

![how-to-proceed_image](how-to-proceed_images/0090.png)

![how-to-proceed_image](how-to-proceed_images/0091.png)

![how-to-proceed_image](how-to-proceed_images/0092.png)

![how-to-proceed_image](how-to-proceed_images/0093.png)

![how-to-proceed_image](how-to-proceed_images/0094.png)

![how-to-proceed_image](how-to-proceed_images/0095.png)

![how-to-proceed_image](how-to-proceed_images/0096.png)

![how-to-proceed_image](how-to-proceed_images/0097.png)

![how-to-proceed_image](how-to-proceed_images/0098.png)

![how-to-proceed_image](how-to-proceed_images/0099.png)

![how-to-proceed_image](how-to-proceed_images/0100.png)

![how-to-proceed_image](how-to-proceed_images/0101.png)

![how-to-proceed_image](how-to-proceed_images/0102.png)

![how-to-proceed_image](how-to-proceed_images/0103.png)

![how-to-proceed_image](how-to-proceed_images/0104.png)

![how-to-proceed_image](how-to-proceed_images/0105.png)

![how-to-proceed_image](how-to-proceed_images/0106.png)

![how-to-proceed_image](how-to-proceed_images/0107.png)

![how-to-proceed_image](how-to-proceed_images/0108.png)

![how-to-proceed_image](how-to-proceed_images/0109.png)

![how-to-proceed_image](how-to-proceed_images/0110.png)

![how-to-proceed_image](how-to-proceed_images/0111.png)

![how-to-proceed_image](how-to-proceed_images/0112.png)

![how-to-proceed_image](how-to-proceed_images/0113.png)

![how-to-proceed_image](how-to-proceed_images/0114.png)

![how-to-proceed_image](how-to-proceed_images/0115.png)

![how-to-proceed_image](how-to-proceed_images/0116.png)

![how-to-proceed_image](how-to-proceed_images/0117.png)

![how-to-proceed_image](how-to-proceed_images/0118.png)

![how-to-proceed_image](how-to-proceed_images/0119.png)

![how-to-proceed_image](how-to-proceed_images/0120.png)

![how-to-proceed_image](how-to-proceed_images/0121.png)

![how-to-proceed_image](how-to-proceed_images/0122.png)

![how-to-proceed_image](how-to-proceed_images/0123.png)

![how-to-proceed_image](how-to-proceed_images/0124.png)

![how-to-proceed_image](how-to-proceed_images/0125.png)

![how-to-proceed_image](how-to-proceed_images/0126.png)

![how-to-proceed_image](how-to-proceed_images/0127.png)

![how-to-proceed_image](how-to-proceed_images/0128.png)

![how-to-proceed_image](how-to-proceed_images/0129.png)

![how-to-proceed_image](how-to-proceed_images/0130.png)

![how-to-proceed_image](how-to-proceed_images/0131.png)

![how-to-proceed_image](how-to-proceed_images/0132.png)

![how-to-proceed_image](how-to-proceed_images/0133.png)

![how-to-proceed_image](how-to-proceed_images/0134.png)

![how-to-proceed_image](how-to-proceed_images/0135.png)

![how-to-proceed_image](how-to-proceed_images/0136.png)

![how-to-proceed_image](how-to-proceed_images/0137.png)

![how-to-proceed_image](how-to-proceed_images/0138.png)

![how-to-proceed_image](how-to-proceed_images/0139.png)

![how-to-proceed_image](how-to-proceed_images/0140.png)

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

Therefore, the outcome is as follows:

![how-to-proceed_image](how-to-proceed_images/0141.png)

Remember to save a snapshot of the machine after this step to ensure that your progress is saved.

![how-to-proceed_image](how-to-proceed_images/0142.png)

![how-to-proceed_image](how-to-proceed_images/0143.png)

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

# **sudo**

## Step 1: Installing *sudo*

Switch to the *root* user and its environment.
```
user@server:~$ su -
Password:
```
Install the *sudo* package.
```
user@server:~$ apt install sudo
```
Verify whether the *sudo* package was installed successfully.
```
user@server:~$ dpkg -l | grep sudo
```

## Step 2: Adding User to *sudo* Group

Add user to *sudo* group.
```
user@server:~$ adduser <username> sudo
```
Alternatively, add user to *sudo* group.
```
user@server:~$ usermod -aG sudo <username>
```
Verify whether user was successfully added to *sudo* group.
```
user@server:~$ getent group sudo
```
To ensure the changes are applied, please reboot your system, then proceed to log in and verify the *sudopowers*.
```
user@server:~$ reboot
<--->
Debian GNU/Linux 10 <hostname> tty1

<hostname> login: <username>
Password: <password>
<--->
user@server:~$ sudo -v
[sudo] password for <username>: <password>
```

## Step 3: Executing commands with superuser privileges

Moving forward, please execute commands that require *root* privileges by using the prefix `sudo`. For example:
```
user@server:~$ sudo apt update
```

## Step 4: Configuring *sudo*

Configure *sudo* with that command.
```
user@server:~$ sudo visudo
```
To limit the number of attempts for *sudo* authentication to a maximum of three *(the default value)*, please add the following line to the file:
```
Defaults        passwd_tries=3
```
If you would like to have a personalized error message displayed when an incorrect password is entered, please follow these steps:
```
Defaults        badpass_message="<custom-error-message>"
```
For a humorous touch, you can replace `badpass_message="<custom-error-message>"` with the word `insults`! 😏

To record a *log* of all sudo commands to `/var/log/sudo/<filename>`, please do the following:
```
user@server:~$ sudo mkdir /var/log/sudo
<~~~>
Defaults        logfile="/var/log/sudo/<filename>"
<~~~>
```
If you wish to store all inputs and outputs of *sudo* commands in an archive located at `/var/log/sudo/`, please follow these steps:
```
Defaults        log_input,log_output
Defaults        iolog_dir="/var/log/sudo"
```
To mandate *TTY* usage, please perform the following steps:
```
Defaults        requiretty
```
To configure the *sudo* paths to `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`, please follow these instructions:
```
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

# **SSH**

## Step 1: Installation and configuration of SSH

Please install the *openssh-server* by executing the following command:
```
user@server:~$ sudo apt install openssh-server
```
To confirm if the installation of *openssh-server* was successful, you can use the following command:
```
user@server:~$ dpkg -l | grep ssh
```
To configure SSH, please follow these steps:
```
user@server:~$ sudo nano /etc/ssh/sshd_config
```
To configure SSH to use Port 4242, please replace the following line::
```
#Port 22
```
with:
```
Port 4242
```
To prohibit SSH login as *root* regardless of the authentication mechanism, please replace the following line:
```
#PermitRootLogin prohibit-password
```
with:
```
PermitRootLogin no
```
To check the status of SSH, please use the following command:
```
user@server:~$ sudo service ssh status
```
Alternatively, you can verify the status of SSH by executing the following command:
```
user@server:~$ systemctl status ssh
```

## Step 2: Installation and configuration of UFW

Please install *UFW* by running the following command:
```
user@server:~$ sudo apt install ufw
```
To confirm whether *UFW* was successfully installed, you can use the following command:
```
user@server:~$ dpkg -l | grep ufw
```
To enable the firewall, please execute the following command:
```
user@server:~$ sudo ufw enable
```
To permit incoming connections on Port 4242, please run the following command:
```
user@server:~$ sudo ufw allow 4242
```
To check the status of *UFW*, please use the following command:
```
user@server:~$ sudo ufw status
```

Please remember to also allow incoming traffic on the required ports in your virtual machine's firewall configuration.

![how-to-proceed_image](how-to-proceed_images/0143a.png)

![how-to-proceed_image](how-to-proceed_images/0143b.png)

![how-to-proceed_image](how-to-proceed_images/0143c.png)

![how-to-proceed_image](how-to-proceed_images/0143d.png)

![how-to-proceed_image](how-to-proceed_images/0143e.png)

![how-to-proceed_image](how-to-proceed_images/0143f.png)

![how-to-proceed_image](how-to-proceed_images/0143g.png)

## Step 3: Connecting to the server using SSH

To connect to your virtual machine using *SSH* on Port 4242, please execute the following command:
```
user@server:~$ ssh <username>@<ip-address> -p 4242
```
You may terminate an *SSH* session at any time by typing the command `logout` and pressing enter.
```
user@server:~$ logout
```
Alternatively, you can terminate an SSH session by executing the command `exit`.
```
user@server:~$ exit
```

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

# **User Management**

## Step 1: Establishing a robust password policy

### Password Age

To configure the password age policy, please follow these steps:
```
user@server:~$ sudo nano /etc/login.defs
```
To configure passwords to expire every 30 days, please replace the following line:
```
PASS_MAX_DAYS   99999
```
with:
```
PASS_MAX_DAYS   30
```
To set the minimum number of days between password changes to 2 days, please replace the following line:
```
PASS_MIN_DAYS   0
```
with:
```
PASS_MIN_DAYS   2
```
To send a warning message to users 7 days before their password expires, you do not need to make any changes as this is the default setting.
```
PASS_WARN_AGE   7
```

### Password strength

In addition, to configure policies for password strength, you will need to install the *libpam-pwquality* package.
```
user@server:~$ sudo apt install libpam-pwquality
```
To confirm whether libpam-pwquality was successfully installed, you can use the following command:
```
user@server:~$ dpkg -l | grep libpam-pwquality
```
To configure the password strength policy, in particular the following line, please follow these steps:
```
user@server:~$ sudo nano /etc/pam.d/common-password
<~~~>
password        requisite                       pam_pwquality.so retry=3
<~~~>
```
To specify a minimum password length of 10 characters, add the following option to the aforementioned line:
```
minlen=10
```
To mandate that passwords contain at least one uppercase character and one numeric character, please follow these steps:
```
ucredit=-1 dcredit=-1
```
To limit the number of consecutive identical characters to a maximum of 3, please perform the following steps:
```
maxrepeat=3
```
To reject passwords that contain the user's username in any form, please perform the following steps:
```
reject_username
```
To configure the required number of changes in the new password from the old password to 7, please follow these steps:
```
difok=7
```
To apply the same password policy to *root*, please perform the following steps:
```
enforce_for_root
```
Once you have implemented all of the necessary changes, your password policy should resemble the following:
```
password        requisite                       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

## Step 2: Creating a new user account

To create a new user account, please execute the following command:
```
user@server:~$ sudo adduser <username>
```
To confirm whether the new user account was created successfully, you can use the following command:
```
user@server:~$ getent passwd <username>
```
Verify newly-created user's password expiry information.
```
user@server:~$ sudo chage -l <username>
Last password change								: <last-password-change-date>
Password expires									: <last-password-change-date + PASS_MAX_DAYS>
Password inactive									: never
Account expires										: never
Minimum number of days between password change		: <PASS_MIN_DAYS>
Maximum number of days between password change		: <PASS_MAX_DAYS>
Number of days of warning before password expires	: <PASS_WARN_AGE>
```
To apply the password policy to the current user account, please follow these steps:
```
user@server:~$ sudo chage -M 30 -m 2 -I -1 <your-current-username>
```
- "-M 30" sets the maximum number of days between password changes to 30, which means that the user must change their password at least once every 30 days.
- "-m 2" sets the minimum number of days between password changes to 2, which means that the user cannot change their password more than once every 2 days.
- "-I -1" disables the password inactive feature, which means that the user's password will not expire even if it is not used for an extended period of time.

## Step 3: Creating a new user group

To create a new group named *user42*, please execute the following command:
```
user@server:~$ sudo addgroup user42
```
To add a user to the *user42* group, please use the following command:
```
user@server:~$ sudo adduser <username> user42
```
Alternatively, you can add a user to the *user42* group by using the following command:
```
user@server:~$ sudo usermod -aG user42 <username>
```
To confirm whether the user was successfully added to the *user42* group, please execute the following command:
```
user@server:~$ getent group user42
```

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

# **cron**

## Configuring a *cron* Job

Please install *net-tools* by running the following command:
```
sudo apt install net-tools
```
To create a script, please follow these steps:
```
nano /path/to/script.sh
```
Please copy and paste the following code into your script file (you may create it to suit your needs):
```bash
#!/bin/bash
arc=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmt=$(lsblk | grep "lvm" | wc -l)
lvmu=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}')
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connexions TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"
```
An explanation for this code can be found <a href=#script-explication>here</a>.

To configure *cron* as the *root* user, please follow these steps:
```
user@server:~$ sudo crontab -u root -e
```
To schedule a shell script to run every 10 minutes, please replace the following line:
```
*/10 * * * * sh /path/to/script
```
To view the list of scheduled *cron* jobs for the *root* user, please execute the following command:
```
user@server:~$ sudo crontab -u root -l
```

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

# **Bonus**

## #1: Installation and configuration of the Linux Lighttpd MariaDB PHP *(LLMP)* Stack

### Step 1: Installation of Lighttpd.

Please install *lighttpd* by executing the following command:
```
user@server:~$ sudo apt install lighttpd
```
To confirm whether *lighttpd* was successfully installed, you can use the following command:
```
user@server:~$ dpkg -l | grep lighttpd
```
To permit incoming connections on Port 80, please run the following command:
```
user@server:~$ sudo ufw allow 80
```

### Step 2: Installation and configuration of MariaDB

Please install *mariadb-server* by executing the following command:
```
user@server:~$ sudo apt install mariadb-server
```
To confirm whether *mariadb-server* was successfully installed, you can use the following command:
```
user@server:~$ dpkg -l | grep mariadb-server
```
To launch the interactive script for removing insecure default settings, please follow these steps:
```
user@server:~$ sudo mysql_secure_installation
Enter current password for root (enter for none): #Just press Enter (do not confuse database root with system root)
Switch to unix_socket authentification [Y/n] n
Change root password? [Y/n] n
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```
To access the MariaDB console, please execute the following command:
```
user@server:~$ sudo mariadb
MariaDB [(none)]>
```
To create a new database, please follow these steps:
```
MariaDB [(none)]> CREATE DATABASE <database-name>;
```
To create a new database user and grant them full privileges on the newly-created database, please follow these steps:
```
MariaDB [(none)]> GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION;
```
To apply the changes and reload the privileges, please execute the following command:
```
MariaDB [(none)]> FLUSH PRIVILEGES;
```
To exit the MariaDB shell, please type `exit` and press enter.
```
MariaDB [(none)]> exit
```
To confirm whether the database user was successfully created, you can log in to the MariaDB console using the following command:
```
user@server:~$ mariadb -u <username-2> -p
Enter password: <password-2>
MariaDB [(none)]>
```
To check whether the database user has access to the database, please follow these steps:
```
MariaDB [(none)]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| <database-name>    |
+--------------------+
```
To exit the MariaDB shell, please type `exit` and press enter.
```
MariaDB [(none)]> exit
```

### Step 3: Installation of PHP

Please install *php-cgi* and *php-mysql* by executing the following command:
```
user@server:~$ sudo apt install php-cgi php-mysql
```
To confirm whether *php-cgi* and *php-mysql* were successfully installed, you can use the following command:
```
user@server:~$ dpkg -l | grep php
```

### Step 4: Downloading and configuring WordPress

Please install *wget* by executing the following command:
```
user@server:~$ sudo apt install wget
```
To download WordPress to `/var/www/html`, please use the following command:
```
user@server:~$ sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html
```
To extract the downloaded content, please execute the following command:
```
user@server:~$ sudo tar -xzvf /var/www/html/latest.tar.gz
```
To remove the tarball, please use the following command:
```
user@server:~$ sudo rm /var/www/html/latest.tar.gz
```
To copy the contents of `wordpress` to `/var/www/html`, please execute the following command:
```
user@server:~$ sudo cp -r wordpress/* /var/www/html
```
To remove the `wordpress` directory, please use the following command:
```
user@server:~$ sudo rm -rf wordpress
```
To create the WordPress configuration file from the sample, please follow these steps:
```
user@server:~$ sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
```
To configure WordPress to reference the previously-created MariaDB database and user, please follow these steps:
```
user@server:~$ sudo nano /var/www/html/wp-config.php
```
Replace the following:
```
define( 'DB_NAME', 'database_name_here' );
define( 'DB_USER', 'username_here' );
define( 'DB_PASSWORD', 'password_here' );
```
with:
```
define( 'DB_NAME', '<database-name>' );
define( 'DB_USER', '<username-2>' );
define( 'DB_PASSWORD', '<password-2>' );
```

### Step 5: Configuration of Lighttpd

To enable the required modules in Lighttpd, please run the following commands:
```
user@server:~$ sudo lighty-enable-mod fastcgi
user@server:~$ sudo lighty-enable-mod fastcgi-php
user@server:~$ sudo service lighttpd force-reload
```

### Step 6: Installation of WordPress

Don't forget to open ports !

![how-to-proceed_image](how-to-proceed_images/0143a.png)

![how-to-proceed_image](how-to-proceed_images/0143b.png)

![how-to-proceed_image](how-to-proceed_images/0143c.png)

![how-to-proceed_image](how-to-proceed_images/0143d.png)

![how-to-proceed_image](how-to-proceed_images/0143h.png)

![how-to-proceed_image](how-to-proceed_images/0143i.png)

![how-to-proceed_image](how-to-proceed_images/0143g.png)

Go on your browser, enter localhost or 127.0.0.1 on the URL bar and name you site, add a password and an email and click on 'Install WordPress'.


![how-to-proceed_image](how-to-proceed_images/0144.png)

Now click on 'Log in'.

![how-to-proceed_image](how-to-proceed_images/0145.png)

Your WordPress is installed, well done ! Now you can configure it.

![how-to-proceed_image](how-to-proceed_images/0146.png)

## #2: File Transfer Protocol *(FTP)*

### Step 1: Installation and configuration of FTP

The first step in the process is to install *vsftpd* by executing the following command:
```
user@server:~$ sudo apt install vsftpd
```
Verify whether *vsftpd* was successfully installed.
```
user@server:~$ dpkg -l | grep vsftpd
```
Please enable the reception of incoming connections through Port 21.
```
user@server:~$ sudo ufw allow 21
```
Please configure the *vsftpd* software.
```
user@server:~$ sudo nano /etc/vsftpd.conf
```
In order to activate any type of FTP write command, please remove the comment symbol "#" from the following lines:
```
#write_enable=YES
#local_enable=YES
#write_enable=YES
#local_umask=022
```
To designate the root folder for an FTP-connected user to `/home/<username>/ftp`, please include the following lines:
```
user@server:~$ sudo mkdir /home/<username>/ftp
user@server:~$ sudo mkdir /home/<username>/ftp/files
user@server:~$ sudo chown nobody:nogroup /home/<username>/ftp
user@server:~$ sudo chmod a-w /home/<username>/ftp
<~~~>
user_sub_token=$USER
local_root=/home/$USER/ftp
<~~~>
```
To restrict a user from accessing files or utilizing commands outside of the directory tree, please remove the comment symbol `#` from the following line:
```
#chroot_local_user=YES
```
To create a whitelist for FTP, please include the following lines:
```
user@server:~$ sudo nano /etc/vsftpd.userlist
user@server:~$ echo <username> | sudo tee -a /etc/vsftpd.userlist
<~~~>
userlist_enable=YES
userlist_file=/etc/vsftpd.userlist
userlist_deny=NO
<~~~>
```

### Step 2: Establishing an FTP Connection to the server

Please use FTP to establish a connection to your virtual machine.
```
user@server:~$ ftp <ip-address>
```
You may end the FTP session at any time.

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

## #3: Fail2ban (Just because I would like to implement it as an additional security measure, in addition to FTP)
As an additional measure, I have elected to install Fail2ban to enhance SSH security against brute force attacks.

Please proceed with the installation of Fail2ban:
```
user@server:~$ sudo apt install fail2ban
user@server:~$ sudo systemctl start fail2ban
user@server:~$ sudo systemctl enable fail2ban

user@server:~$ sudo systemctl status fail2ban
```

Kindly create the local configuration file for Fail2ban at `/etc/fail2ban/jail.local`.
```
user@server:~$ sudo cp /etc/fail2ban/jail.conf /etc/fail2ban/jail.local
```

Please replace the Fail2ban configuration file at `/etc/fail2ban/jail.local` by locating the "SSH servers" section around line 279 and adjusting the [sshd] configurations as follows from:
```
[sshd]

# To use more aggressive sshd modes set filter parameter "mode" in jail.local:
# normal (default), ddos, extra or aggressive (combines all).
# See "tests/files/logs/sshd" or "filter.d/sshd.conf" for usage example and det>
#mode   = normal
port    = ssh
logpath = %(sshd_log)s
backend = %(sshd_backend)s
```
to
```
[sshd]

# To use more aggressive sshd modes set filter parameter "mode" in jail.local:
# normal (default), ddos, extra or aggressive (combines all).
# See "tests/files/logs/sshd" or "filter.d/sshd.conf" for usage example and details.
#mode   = normal
enabled  = true
maxretry = 3
findtime = 10m
bantime  = 1d
port     = 4242
logpath  = %(sshd_log)s
backend  = %(sshd_backend)s
```

Please restart the Fail2ban service:
```
user@server:~$ sudo systemctl restart fail2ban
```
You can use the following commands to check for unsuccessful connection attempts and blacklisted IP addresses:
```
user@server:~$ sudo fail2ban-client status
user@server:~$ sudo fail2ban-client status sshd
user@server:~$ sudo tail -f /var/log/fail2ban.log
```
To test the effectiveness of Fail2ban, you can set a short ban duration (such as 10 minutes) in the SSH settings of the /etc/fail2ban/jail.local configuration file, and attempt to connect to SSH multiple times with an incorrect password in order to trigger a ban.

To view a list of all IP addresses that have been banned by the Fail2ban service, please execute the following command:
```
user@server:~$ sudo fail2ban-client status sshd
```
If you need to remove an IP address from the Fail2ban ban list, you can use the following command:
```
user@server:~$ sudo fail2ban-client set sshd unbanip <ip-to-unban>
```

# **Evaluation**

Please refer to the evaluation questions available <a href="https://github.com/rphlr/42-Evals/tree/main/Rank01/Born2beroot" target="_blank">here</a>.

Please find below some assistance to aid in your evaluation:

## General instructions

### Signature file

## Mandatory part

### How does a virtual machine work?

A virtual machine (VM) is software that simulates the existence of a physical machine. It allows a computer to run multiple operating systems (OS) and software at the same time, each in its own VM.

Here is how a virtual machine generally works:

1. The host computer runs the virtual machine software, which creates one or more VMs.
2. Each VM is configured with a number of resources, such as memory, processors, and virtual disks.
3. The virtual machine software installs an operating system and any necessary software in each VM.
4. Users can access the VMs and run programs on them as if they were using a dedicated physical computer.

The virtual machine software acts as an intermediary layer between the host computer's hardware and the VMs, translating instructions sent to the VMs into instructions that the host computer's hardware can understand. This allows the VMs to function as independent computers, but sharing the host computer's resources.

Virtual machines are commonly used to run software that is not compatible with the host computer's operating system, or to isolate different work environments. They are also often used in cloud computing, where they allow for easy deployment of new instances of software or operating systems without having to purchase new hardware.

### Why Debian rather than Rocky?

The choice of Debian over Rocky was made based on the fact that Debian is generally considered to be a more user-friendly and accessible operating system, particularly for beginners.

### Basic differences between Rocky and Debian?

Rocky Linux is a new Linux distribution that is based on CentOS and designed to be a direct alternative to CentOS. It was created in response to concerns about the future of CentOS, which is no longer developed by Red Hat.

A key difference between Rocky Linux and Debian is that Rocky Linux is based on CentOS, which is itself based on Red Hat Enterprise Linux (RHEL). Debian, on the other hand, is an independent distribution that is not based on any other distribution.

Another difference is that Rocky Linux focuses on providing a stable and reliable platform for enterprise users, while Debian is more broadly focused on providing a stable and reliable operating system for a wide range of users, including personal users, servers, and other production environments.

In terms of software packages, Rocky Linux includes many packages similar to those in CentOS, as well as additional packages from other sources. Debian has a larger repository of pre-compiled software packages, with a focus on free and open source software.

Overall, the main difference between Rocky Linux and Debian is that Rocky Linux is designed to be an alternative to CentOS, while Debian is a standalone distribution with its own development philosophy and community.

### The benefits of virtual machines

Virtual machines are computer programs that allow a computer to run multiple operating systems concurrently. They create a simulated environment on a single physical machine, in which each virtual machine acts as a separate computer with its own operating system, processor, memory, and storage.

There are several reasons someone might use a virtual machine:

1. Testing and development: Virtual machines allow developers to test their software on different operating systems and configurations without having to purchase multiple physical machines.
2. Isolation and security: Virtual machines can be used to isolate certain tasks or applications from the host operating system, which can be useful for security reasons. For example, if you need to run a potentially malicious application, you can do so in a virtual machine, which will contain any damage the application might cause.
3. Resource allocation: Virtual machines allow you to allocate resources (such as CPU, memory, and storage) to each virtual machine as needed, which can be helpful if you have limited physical resources.
4. Compatibility: If you need to run an outdated application that is not compatible with your current operating system, you can use a virtual machine to run the application in an older operating system.

Overall, virtual machines offer a flexible and cost-effective solution for running multiple operating systems and applications on a single physical machine.

### The difference between apt and aptitude

`apt` is a package management program for Debian and its derivatives, such as Ubuntu. It allows for installing, updating, and managing software packages on a system that uses the Debian package management system (dpkg). `apt` stands for "Advanced Packaging Tool".

`aptitude` is also a package management program for Debian and its derivatives, but it uses a different text-mode interface from `apt`. `aptitude` stands for "Advanced Packaging Tool Interface".

Generally, both `apt` and `aptitude` are used to manage software packages on a Debian-based system, but they have slightly different commands and syntax. For example, to update the list of available packages with `apt`, you can use the command `apt update`, while to update the list of packages with `aptitude`, you can use the command `aptitude update`.

It is worth noting that `aptitude` is considered more advanced than `apt`, as it is able to automatically resolve dependencies and conflicts when installing or removing packages. However, `apt` is often faster and easier to use than `aptitude`, as it has a simpler interface and more concise syntax.

### What is AppArmor?

`AppArmor` (Application Armor) is a security system that allows for limiting the privileges and actions of a program or process on a Linux system. It is a kind of "firewall" that protects the system by limiting the actions of a program to those that are explicitly allowed by the security policy defined for that program.

`AppArmor` is primarily used to protect systems against malicious programs and spyware, but it can also be used to limit the actions of a legitimate program that may be misused or to limit programming errors that could compromise the security of the system.

`AppArmor` is built into some Linux distributions, such as Ubuntu, and can be enabled and configured using special configuration files called "AppArmor profiles". These profiles define the allowed actions for each program and can be modified to tailor the security rules to your specific needs.

## Simple setup

### Ensure that the machine does not have a graphical environment at launch

You can verify that no graphical interface is currently active by executing the following command:
```
user@server:~$ ls /usr/bin/*session
```
If no graphical interface is active, your machine should respond with the following output:

![No graphical interface in use](./how-to-proceed_images/0146a.png)

If a graphical interface is active, the command `ls /usr/bin/*session` will display a list of session manager executables.

### Check if UFW is started

```
user@server:~$ sudo ufw status
```

### Verify whether UFW (Uncomplicated Firewall) is currently active

```
user@server:~$ sudo service ssh status
```

## User

### To confirm whether a user is a member of both the `sudo` and `user42` groups, check their group affiliations

```
user@server:~$ groups <username>
```

### Create a new user account

```
user@server:~$ sudo adduser <username>
```

To confirm whether a new user account was successfully created, check the list of users to see if the new account is present.

```
user@server:~$ getent passwd <username>
```

### Create the `evaluating` group

```
user@server:~$ sudo addgroup evaluating
```

### Add user to the group

```
user@server:~$ sudo adduser <username> evaluating
```

Additionally, you can add the new user to a specific group using the following command:

```
user@server:~$ sudo usermod -aG evaluating <username>
```

### Advantages and disadvantages of this password policy

### Check if user has been added to the `evaluating` group

```
user@server:~$ getent group evaluating
```

### Delete a user

```
user@server:~$ sudo userdel -r <user>
```

### Delete a group

```
user@server:~$ sudo groupdel <group>
```

## Hostname and partitions

### Change the hostname

```
user@server:~$ sudo hostnamectl set-hostname <hostname>
```

To confirm whether a hostname change has been implemented without requiring a system restart, please check the current hostname using the appropriate command.

```
user@server:~$ hostname
```

Remember to restart the system:

```
user@server:~$ sudo reboot
```

### Check partitions

```
user@server:~$ lsblk
```

### What is LVM and what it is all about ?

Logical Volume Manager (LVM) is a system for managing disk storage space on Linux systems. It allows you to create logical volumes, which are virtual partitions that can span across multiple physical disks or partitions. This can be useful in a number of situations, such as when you want to create a large logical volume from multiple smaller disks, or when you want to easily resize a volume without having to repartition the disk.

LVM works by creating a volume group (VG), which is a collection of physical disks or partitions that can be used to create logical volumes. Each logical volume is then treated as a separate block device, just like a traditional disk partition. This allows you to use LVM to manage your disk space in a more flexible and dynamic way.

Some of the main benefits of using LVM include:

The ability to easily resize logical volumes without having to repartition the disk.

The ability to create logical volumes that span across multiple physical disks or partitions, allowing you to use all of your available disk space more efficiently.

The ability to easily add or remove physical disks from a volume group without having to reconfigure your disk partitions.

The ability to create snapshot copies of logical volumes, which can be used for backup or testing purposes.

LVM is a powerful tool that can be used to manage your disk space in a more flexible and dynamic way. It is widely used on Linux systems and is an important part of many system administrator's toolkit.

## **sudo**

### Check if sudo is properly installed

```
user@server:~$ dpkg -l | grep sudo
```

### Assign an user to sudo group

```
user@server:~$ sudo usermod -aG sudo <username>
```

### What is TTY?

"TTY" is an acronym for "teletype", which refers to a computer's terminal interface. When using the **`sudo`** command, you may see the **`-t`** option followed by a TTY number, for example **`-t 1`**.

This option allows you to specify which terminal the **`sudo`** command should be run on. By default, the **`sudo`** command is run on the current terminal (the one you are currently on).

Here is an example of using the **`-t`** option with the **`sudo`** command:

```
user@server:~$ sudo -t 1 commande
```

In this example, the **command** will be run on terminal 1.

It is important to note that the **`-t`** option is not required and is generally not used in most cases. It can be useful in certain situations, for example when you want to run a **`sudo`** command on a specific terminal.

### Check sudo settings

```
user@server:~$ sudo visudo
```

#### *Strict rules*

#### *Verify the logs*

## UFW / Firewall

### Check UFW status and ports

```
user@server:~$ sudo ufw status
```

#### *Add a new rule*

```
user@server:~$ sudo ufw allow 8080
```

#### *Delete a rule*

```
user@server:~$ sudo ufw delete <rule_number>
```

## **SSH**

### Check SSH status

```
user@server:~$ sudo service ssh status
```

An alternative method to accomplish this task is as follows:

```
user@server:~$ systemctl status ssh
```

### What is SSH?

Secure Shell (SSH) is a network protocol that allows you to remotely connect to a computer and send it commands remotely. It is commonly used to access remote servers or computers in a secure and encrypted manner, using an encrypted connection.

SSH is widely used to administer remote servers and computers, as well as to transfer files between computers. It is also commonly used to establish a remote connection to a computer in order to run commands and use applications as if you were in front of the computer in question.

To use SSH, you need an SSH client on your local computer and an SSH server on the remote computer you want to connect to. There are many available SSH clients and servers for different platforms, including Linux, macOS, and Windows.

### List open SSH ports

```bash
user@server:~$ sudo nano /etc/ssh/sshd_config
```

## Script

### Script explication

1. The first line of the script indicates that the script is to be executed by the Bash shell.
2. Next, the script defines a series of variables that will be used to store system information. Each variable is initialized with the value returned by an external command call. For example, the pcpu variable contains the number of physical processors on the system, obtained using the grep and uniq commands.
3. Then, the script uses the wall command to display system information on all terminals connected to the system. The information is displayed as preformatted text lines, with each variable inserted at the appropriate place in the string.

Here is a more detailed description of each variable and the external command used to define it:

* **arc**: contains the system architecture, obtained using the **`uname`** command with the **`a`** option which displays all available information about the system.
* **pcpu**: contains the number of physical processors on the system, obtained using the **`grep`** command to find all lines in the **`/proc/cpuinfo`** file that contain the string "physical id", then using **`sort`** and **`uniq`** to remove duplicates and finally **wc** to count the remaining lines.
* **vcpu**: contains the number of virtual processors (or "cores") on the system, obtained using the **`grep`** command to find all lines in the **`/proc/cpuinfo`** file that begin with "processor", then using **`wc`** to count the remaining lines.
* **fram**: contains the total amount of physical memory (in MB) on the system, obtained using the **`free`** command with the **m** option to display memory in MB, then **`awk`** to extract the second column from the line that begins with "Mem:".
* **uram**: contains the amount of used physical memory (in MB) on the system, obtained using the **`free`** command with the **m** option to display memory in MB, then **`awk`** to extract the third column from the line that begins with "Mem:".
* **pram**: contains the percentage of used physical memory on the system, obtained using the **`free`** command without options, then **`awk`** to extract the third column (corresponding to used memory) and divide it by the second column (corresponding to total memory) and multiply the result by 100. The **`printf`** command is used to format the result with two decimal places.
* **fdisk**: contains the total size of the disk (in GB) on the system, obtained using the **`df`** command with the **`Bg`** option to display size in GB and **`grep`** to keep only the lines that begin with "/dev/", except those that end with "/boot$" (this excludes the boot partition from the calculation). **`awk`** is used to add up the sizes of all the partitions and display the result.
* **udisk**: contains the amount of used disk space (in MB) on the system, obtained similarly to **`fdisk`**, but using the **`df`** command with the **`Bm`** option to display size in MB and using the third column (corresponding to used space) instead of the second.
* **pdisk**: contains the percentage of used disk space on the system, obtained similarly to **`pram`**, but using the **`df`** command with the **`Bm`** option to display size in MB and using the third column (corresponding to used space) and the second column (corresponding to total size) instead of physical memory. The **`printf`** command is used to format the result with one decimal place.
* **cpul**: contains the CPU usage percentage of the computer, obtained using the **`top`** command and retrieving the value associated with the line starting with "%Cpu".
* **lb**: contains the date and time of the last boot of the computer, obtained using the **`who -b`** command and retrieving the value associated with the 3rd and 4th columns of the result. The **`who -b`** command displays information about system starts and stops, such as the date and time of the last boot and the last stop.
* **lvmt**: contains the number of storage devices using LVM (Logical Volume Manager) on the computer, obtained using the **`lsblk`** command and counting the number of lines containing the string "lvm".
* **ctcp**: contains the number of TCP connections currently being established on the computer, obtained using the **`/proc/net/sockstat`** and **`/proc/net/sockstat6`** files and retrieving the value associated with the line starting with "TCP:".
* **ulog**: contains the number of users logged in to the computer, obtained using the **`users`** command and counting the number of words (i.e., number of users) in the result.
* **ip**: contains the IP address of the computer, obtained using the **`hostname -I`** command.
* **mac**: contains the MAC address of the computer's network interface, obtained using the **`ip link show`** command and retrieving the value associated with the line starting with "link/ether".
* **cmds**: contains the number of commands executed with sudo on the computer, obtained using the **`journalctl`** command and counting the number of lines containing the string "COMMAND". The **`journalctl`** command displays entries from the system journal, which are events recorded by the operating system. By specifying the filter **`_COMM=sudo`**, only journal entries related to commands executed with **`sudo`** are selected. By counting the number of lines containing the string "COMMAND", the number of commands executed with **`sudo`** is obtained.
* **wall**: sends the message contained in quotation marks to all users logged in to the computer, using the **`wall`** command. The message contains several information about the system, such as the architecture, memory and disk usage, CPU load, date of last boot, IP and MAC address of the network interface, etc. This information is obtained using the variables described above.

### What is cron?

Cron is a daemon (a background process) that runs commands or scripts at predefined intervals of time, called "cron times". It is primarily used on Unix and Linux systems to schedule tasks to be run automatically.

Cron uses a configuration file called "crontab" that defines the tasks to be run and their frequency of execution. Each line in the crontab corresponds to a task to be run, and contains five fields that define when the task should be run.

Here is an example of a crontab that runs a command every day at midnight:

```
0 0 * * * /path/to/script
```

Each field in the crontab can be defined in different ways:

* An integer represents an absolute value (for example, to run a task every day at midnight, you would set the first field to 0).
* An asterisk (*) means that the task should be run at all possible values for that field (for example, to run a task every hour, you would set the second field to *).
* A list of values separated by commas (e.g. 1,2,3) means that the task should only be run when the field matches one of these values (for example, to run a task every day of the week except Saturday and Sunday, you would set the fifth field to 1-5).
* A range of values separated by a dash (e.g. 2-5) means that the task should be run when the field matches a value within that range (for example, to run a task every day of the week from Tuesday to Friday, you would set the fifth field to 2-5).

You can use the **`crontab -e`** command to edit your crontab and add or modify tasks to be run. You can also use the **`crontab -l`** command to view the contents of your crontab.

## Bonus

### WordPress site

To verify if WordPress is functioning correctly on your server, simply navigate to the following web address: `http://127.0.0.1`:

![how-to-proceed_image](how-to-proceed_images/0147.png)

If you are not currently logged in to WordPress, you can access the login page via the following link: `http://127.0.0.1/wp-login.php`.

### FTP service

To see if FTP is properly working, you can try to install an app in your WordPress instance, it will ask ftp login infos.

You can now connect to your WordPress site via FTP to install extensions:
![how-to-proceed_image](how-to-proceed_images/0148.png)

Ensure that you have granted the correct permissions to the WordPress folder by executing the following command:
```
user@server:~$ sudo chmod -R 777 /var/www/html
```
To demonstrate the functionality and graphical interface of the FTP connection, you may install a WordPress FTP plugin using my account.

![how-to-proceed_image](how-to-proceed_images/0149.png)

### Fail2ban

To test whether Fail2ban is functioning properly, attempt to login to your machine using SSH and an incorrect password three times. This will trigger the Fail2ban system to automatically blacklist your IP address.

To view it, execute the following command:
```
user@server:~$ sudo fail2ban-client status sshd
```
You can now remove it by using the following command:
```
user@server:~$ sudo fail2ban-client set sshd unbanip <ip-to-unban>
```

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

# My B2BR project evaluation

<div align="center">

|      Passed ?      |   Note  |
|--------------------|:-------:|
| ✅                 | 125/100 |

</div>

<div align="center" style="text-align:center">
	<img src="https://raw.githubusercontent.com/rphlr/rphlr/main/imgs/separator.gif" alt="Separator" width ="200">
</div>

This module was done by [rphlr](https://rphlr.ch).