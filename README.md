<p align="center">
<img src="https://www.davidjohncoleman.com/wp-content/uploads/2017/06/HBTN-Borderless-CMYK-Logo-Vertical-Color-Black@1200ppi-300x236.png">
</p>

<h1 align="center"> simple_shell project </h1>

### Description
In simple_shell project we code from zero our own custom printf function. Native printf function allows you to print with certain formats. We handle most basic format so you can print chars, strings, positive and negative numbers, hex, octa and binary numbers among other formats.
You can see man of sh to get an idea about how shell works.

### Usage
First, you have to clone this repo ```$git clone https://github.com/davidgonzalezfx/simple_shell.git```

Compile

	gcc -Wall -Werror -Wextra -pedantic *.c -o executable_filename

Execute: see more in <a href="#examples">examples<a/>
``` bash
Interactive mode:
$ ./hsh
./hsh$ [put_commands and_arguments]

Non-interactive mode
$ echo "[put_commands and_arguments]" | ./hsh
```

### Built-ins
* exit & exit(status)
* env
* setenv & unsetenv
* cd
* help

### Examples
<div id="examples"><div/>

1. Absolute path commands
- non interactive
```bash
$ echo "/bin/pwd" | ./hsh
$ /home/davidgonzalezfx/simple_shell
```
- interactive mode
``` bash
$ ./hsh
./hsh$ /bin/echo hello world
./hsh$ helo world
./hsh$ exit
$
```

	 

### Project files
| File        | Description |
| ----------- | ----------- |


### Full documentation
For more infor about this project you can run the man page

``` bash
$ ./man_1_simple
[PENDING]
```

### Flowchart
Go to this link to see the flowchart of our project: [flow chart](https://draw.io)

#### Authors
David Gonzalez - [@davidgonzalezfx](https://github.com/davidgonzalezfx)<br>
Nicolas Forero - [@nsforero10](https://github.com/nsforero10)<br>