<h1>Assignment 1
CMPE 283
Discovering VMX Features</h1>

Question 1 <br>
Arselan (me)<br>
Used VMWare fusion as a Virtual Machine <br>
Researched and built/compiled Linux Kernel source code and got the environment setup. <br>
Implemented 283-1.c file. <br>
Tested it by loading the new module and verified the output.<br>
Rajakumari<br>
Researched about VMX virtualization features and MSRs. <br>
Researched Intel 64 and IA-32 Architectures Software Developer’s Manual Vol:3C about various VMX configuration MSRs to the capabilities and features as listed in<br> the assignment which were used in the 283-1.c file implementation. <br>
Worked on the 283-1.c file implementation. <br>
Question 2 : Implementation of the software<br>
Configure a Linux Machine. <br>
Download VMWare Fusion or any VM of your choice. (or use parallels) <br>
Download Ubuntu 20.04<br>
Create a new VM in VMWare Fusion by dragging the .iso file which will install Ubuntu OS in the VM.<br>
Specs used: <br>
CPU processor cores: 2<br>
Memory: 4 GB<br>
Disk: 105 GB<br>
Build Linux Kernel Source code<br>
Download Linux Kernel Archive from kernel.org. <br>
Download the tarball file (5.9 used for this assignment)<br>
Install following packages:<br>
Run command ‘sudo apt install build-essential rsync gcc bc bison libssl-dev libncurses5-dev libelf-dev’<br>
Update grub file <br>
Run command ‘sudo update-grub’<br>
Get the Linux Kernel tarball file and untar it<br>
Run command ‘wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.9.tar.xz’<br>
Create a new directory ‘LinuxKernel’ and untar the file<br>
Run command ‘mkdir yourdirname’<br>
Run command ‘tar xvf linux-* -C yourdirname/ --strip-components=1’<br>
Configure the Kernel Compilation and Compile the Kernel<br>
Copy the config file that came with the linux distribution. <br>
Run command ‘cp /boot/config-$(uname -r) ./.config’<br>
Compile kernel by running this command in your directory.<br>
Run command ‘make deb-pkg’<br>
Kernel will compile. This process took 5.5 hrs for me. <br>
Make sure Kernel has compiled successfully. <br>
![Screenshot](5.png)<br>

Create a new Linux Kernel module that will query various MSR’s to determine Virtualization features. <br>
Inside your LinuxKernel directory create a new directory<br>
Run command ‘mkdir 283assignment1’<br>
Go to the 283assignment1 directory and create a cmpe283-1.c file<br>
Run command ‘mkdir cmpe283-1.c’<br>
Add the required functionality. <br>
Download the file ‘cmpe283-1.c’ and ‘makefile’ from the github link provided and run command ‘make’ while you are in the 283assignment1 directory. <br>
This will create ‘cmpe283-1.ko’ which we will use to load new modules into Kernel.<br>
![Screenshot](6.png)<br>
Load the new module in the Kernel<br>
Run command ‘sudo insmod ./cmpe283-1.ko’<br>
It will call init_module() which will call detect_vmx_features();<br>
To stop use command ‘sudo rmmod ./cmpe283-1.ko’<br>
Call cleanup_module()<br>
Run command ‘dmesg’ to see syslog. <br>

Output of the module<br>
![Screenshot](1.png)
![Screenshot](2.png)
![Screenshot](3.png)
![Screenshot](4.png)
