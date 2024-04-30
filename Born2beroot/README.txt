/************************************** I N S T A L L A T I O N **************************************/

ENTER AS ROOT:
    $ su -

INSTALL SUDO: 
    $ apt-get update -y
    $ apt-get upgrade -y
    $ apt install sudo

ADD USER IN A GROUP: 
    $ su -
    $ usermod -aG sudo your_username

RESIZE:
    $ lvresize --resizefs --size 2.5G /dev/mapper/user_name--vg-home
    $ lvresize --resizefs --size 6.4G /dev/mapper/user_name--vg-home

INSTALL APPARMOR:
    $ sudo apt update
    $ sudo apt install apparmor
    $ sudo mount -t apparmor none /sys/kernel/security/apparmor
    $ sudo aa-status  # Check the status of AppArmor
    $ sudo systemctl enable apparmor.service  # Enable AppArmor
    $ sudo systemctl start apparmor.service
    $ sudo systemctl status apparmor.service
    $ sudo reboot

INSTALL SELINUX: 
    $ sudo apt-get install selinux-basics selinux-policy-default auditd
    $ sudo selinux-activate
    $ sudo reboot

INSTALL GIT: 
    $ apt-get update -y
    $ apt-get upgrade -y
    $ apt-get install git -y

INSTALL WGET: 
//wget is a free and open source tool for downloading files from web repositories.
    $ sudo apt-get install wget

INSTALL VIM:
    $ sudo apt-get install vim

INSTALL OhMyZsh:
    $ sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"

INSTALL SHH:
    $ sudo apt-get update
    $ sudo apt install openssh-server
    $ service ssh restart

INSTALL UFW: 
    $ apt-get install ufw
    $ sudo ufw enable           // Firewall is active and enabled on system startup
    $ sudo ufw allow ssh
    $ sudo ufw allow 4242

/*********************************************** S S H ***********************************************/
    $ sudo nano /etc/ssh/sshd_config
    $ sudo service ssh restart
    $ sudo systemctl restart ssh
    $ ssh your_username@127.0.0.1 -p 4242 //also localhost instead of 127.0.0.1
    $ sudo ufw allow <port>
    $ sudo ufw deny <port>
    $ sudo ufw delete allow <port>
    $ sudo ufw delete deny <port>

/*********************************** P A S S W O R D   P O L I C Y ***********************************/
    $ sudo apt-get install libpam-pwquality
INTO /etc/pam.d/common-password:
    password    requisite         pam_pwquality.so retry=3 lcredit =-1 ucredit=-1 dcredit=-1 maxrepeat=3 usercheck=0 difok=7 enforce_for_root
    password [success=2 default=ignore] pam_unix.so obscure sha512 minlen=10
INTO /etc/login.defs:
    PASS_MAX_DAYS 30
    PASS_MIN_DAYS 2
    PASS_WARN_AGE 7
        ↓
    $ sudo chage -M 30 <username/root>
    $ sudo chage -m 2 <username/root>
    $ sudo chage -W 7 <username/root>

INTO sudo visudo: 
    Defaults     passwd_tries=3
    Defaults     badpass_message="Wrong password. Try again!"
    Defaults     logfile="/var/log/sudo/sudo.log"
    Defaults     log_input
    Defaults     log_output
    Defaults     requiretty 

INTO /etc/security/pwquality.conf:
{
    difok = 7
    minlen = 10
    dcredit = -1
    ucredit = -1
    maxrepeat = 3
    usercheck = 1
    retry = 3
    enforce_for_root
}

    $ sudo passwd <user/root> //to change passwd

/******************************************** G R O U P S ********************************************/
    $ sudo groupadd user42
    $ sudo groupadd evaluating

/******************************************** C H E C K S ********************************************/
    $ getent group sudo
    $ getent group user42
    $ git --version
    $ sudo systemctl status ssh
    $ sudo grep Port /etc/ssh/sshd_config
    $ sudo ufw status numbered/verbose
    $ sudo service sshd status
    $ sudo whoami
    $ chage -l <username/root>
    $ getent group
    $ groups
    $ lsblk
    $ dpkg -l | grep sudo –
    

/**************************************** E V A L U A T I O N ****************************************/
    $ sudo ufw status numbered
    $ sudo ufw delete (that number, for example 5 or 6)
    $ sudo adduser new_username
    $ sudo usermod -aG user42 your_username
    $ sudo usermod -aG evaluating your_new_username
    $ getent group user42
    $ getent group evaluating

    $ hostnamectl
    $ hostnamectl set-hostname new_hostname
INTO $ sudo nano /etc/hosts
    127.0.0.1       localhost
    127.0.0.1       new_hostname
    $ sudo reboot

    useradd                                 : creates a new user.
    usermod                                 : changes the user’s parameters: -l for the username, -c for the full name, -g for groups by group ID.
    userdel -r                              : deletes a user and all associated files.
    id -u                                   : displays user ID.
    users                                   : shows a list of all currently logged in users.
    cat /etc/passwd | cut -d ":" -f 1       : displays a list of all users on the machine.
    cat /etc/passwd | awk -F '{print $1}'   : same as above.
    groupadd                                : creates a new group.
    gpasswd -a                              : adds a user to a group.
    gpasswd -d                              : removes a user from a group.
    groupdel                                : deletes a group.
    groups                                  : displays the groups of a user.
    id -g                                   : shows a user’s main group ID.
    getent group                            : displays a list of all users in a group.
    dpkg -l | grep sudo                     :to show that sudo is installed
    sudo ufw status numbered
    sudo ufw allow port-id
    sudo ufw delete rule number
    ssh your_user_id@127.0.0.1 -p 4242 -    :do this in terminal to show that SSH to port 4242 is working

    cd /usr/local/bin                       :to show monitoring.sh
    sudo crontab -u root -e                 :to edit the cron job
    change script to */1 * * * * sleep 30s && script path   :to run it every 30 seconds, delete the line to stop the job from running.

    
/**************************************** M Y     S C R I P T ****************************************/
    $ sudo apt-get update -y
    $ sudo apt-get install -y net-tools

#!/bin/bash
get_arch() {
    uname -srvmo
}

get_pcpu() {
    grep 'physical id' /proc/cpuinfo | uniq | wc -l
}

get_vcpu() {
    grep processor /proc/cpuinfo | uniq | wc -l
}

get_memory_total() {
    free -m | awk 'NR==2{printf "%sMB", $2}'
}

get_memory_usage() {
    free -m | awk 'NR==2{printf "%s/%sMB (%.2f)", §3, $2, §3*100/$2}'
}

get_disk_usage() {
    df -h | awk '$NF=="/"{printf "%d/%dGB (%s)", $3*1000, $2, $5}'
}

get_cpu_load() {
    top -bn1 | grep load | awk '{printf "%.2f%%\n", $(NF-2)}'
}

get_last_boot_time() {
    who -b | awk '{print $3" "$4" "$5}'
}

is_lvm_used() {
    lsblk | grep -q lvm && echo "yes" || echo "no"
}

get_established_connection() {
    grep TCP /proc/net/sockstat | awk '{print $3}'
    echo " ESTABLISHED"
}

get_logged_in_users() {
    who | cut -d " " -f 1 | sort -u | wc -l
}

get_network_info() {
    local ip=$(hostname -I | awk '{print $1}')
    local mac= $(ip a | grep link/ether | awk '{print $2}')
    echo "IP $ip ($mac)" 
}

count_sudo_commands() {
    grep COMMAND /var/log/sudo/sudo.log | wc -l
    echo " cmds"
}

get_another_arch() {
    hostanamectl | grep 'Operating System' | cut -d ' ' -f5- $(awk -F':' '/^model name {print $2}' /proc/cpuinfo | uniq | sed -e 's/^[ \t]*//')
}

message=$(cat <<-EOF
#Architecture       :$(get_arch)
#CPU physical       :$(get_pcpu)
#vCPU               :$(get_vcpu)
#Memory Usage       :$(get_memory_usage)
#Disk Usage         :$(get_disk_usage)
#CPU Load           :$(get_cpu_load)
#Last Boot          :$(get_last_boot_time)
#LVM use            :$(is_lvm_used)
#Connection TCP     :$(get_established_connection)
#User log           :$(get_logged_in_users)
#Network            :$(get_network_info)
#Sudo               :$(count_sudo_commands)
EOF
)

echo "message" | wall