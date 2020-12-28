#! /bin/bash
# prior to compile and install update Make file and customize EXTRAVERSION
# run from root of linux mainline or next after making changes
# dont forget to checkpatch.pl -f <file> !
# do git oneline to get formatting of patch subject
echo grabbing latest changes...
git checkout master && git stash && git pull
echo updating config...
cp /boot/config-5.9.16-200.fc33.x86_64 .config
sleep 5
make listnewconfig
lsmod > /tmp/my-lsmod
make LSMOD=/tmp/my-lsmod localmodconfig
echo compiling kernel
sleep 5
make -j4 all
# get all dmesg to compare after install
echo collecting dmesg
sleep 5
dmesg -t > dmesg_current
dmesg -t -k > dmesg_kernel
dmesg -t -l emerg > dmesg_current_emerg
dmesg -t -l alert > dmesg_current_alert
dmesg -t -l crit > dmesg_current_alert
dmesg -t -l err > dmesg_current_err
dmesg -t -l warn > dmesg_current_warn
echo installing kernel
sleep 5
sudo make modules_install install
echo restart to boot into modified kernel
# if all good git commit -m "message" <file>
# git format-patch -1 <commitId>
# mutt -H 000-mychange.patch

# On first compile there might issues 
# install openssl-devel, dwarves, elf-utils and try make prepare
