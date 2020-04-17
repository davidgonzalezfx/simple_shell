<p align="center">
<img src="https://www.davidjohncoleman.com/wp-content/uploads/2017/06/HBTN-Borderless-CMYK-Logo-Vertical-Color-Black@1200ppi-300x236.png">
</p>

<h1 align="center"> simple_shell project </h1>

### Description
In simple_shell project we code from zero our own custom printf function. Our shell must have the same behavior than **sh** shell in output and error. We had to learn about the workflow of a command line interpreter, what's a pid and ppid, learn about manage processes, how to manipulate the environment of the current process, the difference between a function and system call, how to create processes, how to get PATH variables, execute commands with execve. And off course be carefull with memory leaks and write beautiful code with Betty style.

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
helo world
./hsh$ exit
$
```
2. short command
- non interactive
```bash
$ echo "pwd" | ./hsh
$ /home/davidgonzalezfx/simple_shell
```
- interactive mode
``` bash
$ ./hsh
./hsh$ echo hello world
helo world
./hsh$ exit
$
```
3. built-ins
- non interactive
```bash
$ echo "exit" | ./hsh
$ echo $?
0
```
- interactive mode
``` bash
$ ./hsh
./hsh$ exit 98
$ echo $?
98
```

**Some error output**
``` bash
$ ./hsh
./hsh$ ls /non_existing_folder
ls: cannot access '/non_existing_folder': No such file or directory
./hsh$ exit
$ echo $?
2
```
``` bash
$ echo "non_valid_command" | ./hsh
./hsh: 1: non_valid_command: not found
$ echo $?
127
```
	 

### Project files
| File        | Description |
| ----------- | ----------- |
| AUTHORS     | File with names of the owners and authors of this project |
| Readme.md   | Nutshell description of simple_shell project |
| aux_funs.c  | Auxiliar functions <br> **signal_exit:** handler for SIGINT signals <br> **_calloc:** allocate memory and fills it with zeros
| built-ins.c | Built-ins functions: <br> **check_word:** evalute alpha chars in string <br> **exit_built_in:** stop execution of shell <br> **env_built_in:** prints environment variables |
| core_funs.c | Heart of simple_shell <br> **check_builtin:** check if first argument is a built-int <br> **not_found_error:** handler for print error when command is not found <br> **simple_exec:** decision flow for command execution|
| path_funs.c | Function to check command in path <br> **_getenv:** search variable in environment vars <br> **cmd_path:** concat first argument with PATH dirs |
| shell.h     | Header file <br> **All includes** <br> **All prototypes** <br> **Definition of struct params** |
| simple_shell.c | Initialize the simple_shell execution: <br> **test:** <br> Remove \n last char readed with getline <br> Tokenize and save in argv all arguments readed <br> Calls simple_exec <br> **main:** <br> Initialize params struct vars <br> Set signal listenes <br> Print prompt (interactive mode) <br> Read arguments with getline <br> Handle CTRL + D to stop execution|
| string_funs.c  | First string functions file <br> **_strcat:** concat string (no malloc) <br> **_strlen:** get length of string <br> **rev_string:** reverse a string <br> **_itoa:** convert int to string <br> **_strcmp:** compare two strings |
| string_funs2.c  | Second string functions file <br> **_strchr:** search char in string <br> **_strcpy:** copy string in other one <br> **str_concat:** concat string (malloc) <br> **_atoi:** convert string num, to int|


### Full documentation
For more info about this project you can run the man page:

`$ ./man_1_simple`

### Flowchart
Go to this link to see the flowchart of our project: [flow chart](https://app.diagrams.net/?lightbox=1&highlight=0000ff&layers=1&nav=1&title=shell.drawio#R%3Cmxfile%20pages%3D%225%22%3E%3Cdiagram%20id%3D%22ZPFKSTzHN-5zQBHHbEto%22%20name%3D%22start%22%3E7Vxbc9o4FP41zLAPMJZ85RFIms02TTulnW32JSNAgFtjeW0RIL%2B%2Bki3jixwgxMRKprxgHUuydc75zk2Clj5cbq5CFCw%2BkSn2WlCbblr6RQtCALUe%2B%2BKUbUKxbJgQ5qE7FZ0ywsh9xIKoCerKneKo0JES4lE3KBInxPfxhBZoKAzJuthtRrziUwM0xxJhNEGeTP3XndJFQnWgndH%2Fxu58kT4ZWGLBS5R2FiuJFmhK1jmSftnShyEhNLlabobY48xL%2BXJ987gcOH3Anvxr%2BPHD4p%2F%2FUL%2BTTPbhOUN2SwixT0%2BeGn0En6Lrxy%2FBxffoOx197fz0%2FY6Q5QPyVoJfYq10mzIQTxk%2FRZOEdEHmxEfeZUYdhGTlTzF%2FjMZaWZ8bQgJGBIz4E1O6FcqBVpQw0oIuPXH3yPUJPkRkFU7wnkUJeVEUzjHd00%2FMxxeY0xXBvStMlpiGW9YhxB6i7kNRoZDQy%2FmuX8Z7diHY%2FwxRaJIoRt%2F6X7%2FJ8vA8hh3O9%2FXCpXgUoJgZawbfl3D1AYcUb%2FbyQdzVLdA1k0HrDFFAE7RFDk2mdSZmWe9Rb1PzeEhvTaX0FkiiuPZd6iKPc43Tw6gFLY8taDAO2dWcX6GHFhzyNTALz4haPFDTEqLH%2BZ%2FSgDzYw355CJMBWkb8Qu4edAsTJg25k4%2BWeNeJvZ850FrmRVVPvHHpfbLe3GvI%2FdgU8er5LKLf7febG0lTMz0EDaLaEJjapo5QkzGuWzLGQeof69csTWLVK4CaS%2FdH7vqOT8UMXtK62IiZ48Y2bfhsvT%2Fyjdwo3syGxa10XM0GxDzSgNhqGRCjSTFnor3L3Tkk5kyydwXBKiVmoFaAY8oBDnt9tl53zgTHLbMbUezjKn8xur66vmWxkNZhFLTkNjGmx8PZ6Hsup8ph30ZfKoexW%2FfXV7eKGmPTKBhj2KswxqndzRtj61y22JaEl4gtZnz7L4mNLFkK%2BGUQkgmOosOsHKPJr3nM%2FM8r6rk%2BPjOLTUdTjMXAatQOnuTunmcHZ8SnQ%2BKxiI%2BvTtfiDw%2Fo0Bh7g50CpF18wrWg9ij72DAbqBVnQxmCt58rNeaGs5MH2R6DKCNPGOMwY%2BiAo8OdIK8vbizd6TTRIhy5j2gcT8IFEhDXp%2FECzAEPX58WHacL3QLwkHHcq%2FYSdHc1IfFirXzZpQrSHaaOBtALsO6I5tEyErN%2F4RzIpgZm14G93McpPEUvzkdms4i7tpLEd298uhLocpWgCaOxH7BlnXhKd5oCNuwpBWxdzqDvLkd7kZ0TRd0gP01w%2B5X1xcjWusA2zSKwQT3ALk1qdS37tcAMZMGLekg5jk0pUYD8glZY%2F694%2BTmWVGeGlq7HXqjPyw1pvMvkphtcT0KXB9klatyTF1Ai5EedCIfuLK5V8BvxnFGsDnxGYASb3T0mT9oRqsdvenhGs7fZvfYlbDm9Vr%2BiOpJSGOOSRSXky88f2GztDpAjynBBluPVEZHk2YJyq1ghMWw5YuxVFUi0s0WMjhLeoG47fnR%2Bq1gdQ05wZyHG7aA7Xs1mFQqtQqYJ7GIaZBpNp0FQtorqhzh1Q8A%2BFgJqhTJQNkjvI5SBTwHrlCQFQKMUdrwwSTl%2FqAJl2%2FYePM2xMIOGUjADcinAjRBjXDuiU9dXMHYCvaKbsSrcjFPhZZyzhU49iYXrkLGmDZJ4OBfMmkM%2FH9ryu1XhaaPePGWr2bj3NiS%2BYn8q24qmDzEA2%2B4WE0rbquDdqx5q0HUljKySxZ20ZnPQVOtQKVMNZTszWpA1Z01IlkHFnlXxSARbLN8MadeQQpxHcqdvajVvrHSnCXydsuOiJCbrh1p1jU6HpRy1fOIkMQpiVKYT%2FTBE21w3kSUc%2FRzbcUoqlsxYb0VfNhAsvUG%2FKjXzbSVNKbxqSZq0ngYL0nlh%2Fff8OZMBJcm%2Bj2S4VrnaplXTFh3s6lVbdK8gaDnm%2FRO3lXzEwbjN0JWK23QZvOneTLKD4o%2Bj4A3vzMTBZeeJXRggqW%2FjBYTy5oudGqHGNl8MNc6gK4n6FMyHUa%2FWGRtDLqy9D5dt1HnIBprF0y8v3Yo%2Fv4c23%2BKekmpYTdN1VbAqV8velYfOzk5kv4Ep%2BWn13bTjNH1GwpDz6z%2FQL3nfw27aUQv68m5ksWpKcUTbwRuvl5qlclRPa7peasjb%2B5zTEptrO%2FyvmgiA1rgMzEbM1ym%2FllLS5NUfxFRXowxQ3OwwwHlq1uXnAKCX%2FgagNMDWtZcNSFdy1qp4Kqacpan4ES%2FrNEjCo7ds58v7YkA748YYa2b%2FWJFIK%2FvfD%2F3yNw%3D%3D%3C%2Fdiagram%3E%3Cdiagram%20id%3D%22wnPK8H0QMCBDu31KDfzO%22%20name%3D%22test%22%3E7Vxbc5s4FP4t%2B8A03Zl0QFz9GCdpdnayu%2Bmk6W72pSODbGgwYkEkdn79SiCuosFu7QCO82BLBwmsc%2FRJ5ztHRFLPl6urCIbuH9hBvgRkZyWpFxIACpAn9ItJ1pnEMEEmWESewxuVglvvGXGhzKWJ56C41pBg7BMvrAttHATIJjUZjCL8VG82x379qSFcIEFwa0NflP7tOcTNpBYwS%2FlvyFu4%2BZMVgw94CfPGfCSxCx38VBGpl5J6HmFMstJydY58prxcL8By1%2FKFLd%2F9%2FsU%2FsxY360%2Bzf0%2Bzm33cpksxhAgF5Idv%2FWUWXJF5OPn86fme2Kd362Vyc8pt%2BQj9hOuLj5WscwUih%2BqTV3FEXLzAAfQvS%2Bk0wkngIPYYmdbKNtcYh1SoUOE3RMiaTw6YEExFLln6%2FKoPZ8ifQvthkd7qHPs4opcCHLDbz3FAeFcF8HreRAKqnP5R%2BYZa4tqMcRLZ6AXVcKsTGC0QeaEdvx9TU2XGcRtcIbxEJFrTBhHyIfEe69MS8tm9KNqVFqQFbsQtDCoLBv2MYiIa1fcpAJl2n1yPoNsQprp4omtA3TTbKfURRQStXlQDv6oaygc967SuLxhPJUoVmTdxKwjVjT2pTjtioWOOd2JBHRQWFMGgHtUGHcZDIAHDpwOZziJaWrCS7UJaln%2BFyYp%2Bpc3lP%2B%2Bur4U5UFpY6YbPfuy1Bcx0rQ6yNpTlG1wVZYa8J6MYR5R1oKcTZfqgUKYKBq1CKCaR7UYns2Q%2BlwB9gPxO0s%2BDd%2B8PC1atm9erwso6wqoDLp2wMgcFq4lg0PvL21abXjOl1%2B0AfW8R0LJNNYioeqdsanuUFJ3xC0vPcTKTo9h7hrP0fkz3IaZ7ZDoWfSrpFz9ltRcnahNrBQPkP0aqkqw2DJ7KH4BmgDoOs9rGFuI3v8GZY5A3wfN5jIhgwuI3%2FIRLIvokR5xuidN8rR0IUPX2%2Fa%2B5vbl4OUviEWxtZn1rU1Vxa7NadjZrXzubavaBELTyyD%2BsO2WpWe2%2BcuVixe%2BcVtZ5JaDjrXRi1fvqtbJbWsv7vYxGFDhnLA5Wk3z0mBLT3j2h1RwnWk0BrTXGx7xT%2BjFq51TPHc8cwVrfzqkicoTjrtfARzeQwKCApIiRxjSuwoEkixGW8JSW4JKhJa3TAT8W7b9S59TH9okCrIwnWmOniMCooVBrQ6FpvCYKj6GXTnB1o3BYwRdF3M8OgyYWk3UnPNGSed8BM0OR8B%2FRuTU6rWGhEwg2%2FYXppXUjPBTCqGu6sNG9KmFUREYeIZJEzDkpptyAUqE6MBupUF03RV%2FhVXOhQO9j8RkO6e5robM2XOjAsFi1IqYfGkkggh9OmutemRSi8v8Sdo5mWquMnQJo9ei0YbZQAE0TYb03CqBqR1j3AGuwKcfPOeNAYA1Ejs%2F8l4OKb5tGz%2FHt3M9%2Fg45%2FNx60XeOhwev4pNAa%2BXxLblg7gzjvtXvyB8QA6WHQ%2BGJyvxUaD8RThPMIIcH3YZzvvRgjHRlRMfPD4L0RFVXt1aOp%2BDOld9Ph0Sg1f6Z0b0bl0RgbruDqsI5Ha2M4f1HJ%2BNo%2BjGPPlqpJ3%2F15UbszuzYsfgrE1MdBObETuW8nVsxDxN4y9NFXtEL2iUjkYxeGrBhG2EbxBiqfFWj5KyG%2BF6CBmEKrJ9snvZ8EVd8un%2Bg%2BYb0x8RjWYVB1DMmh4W5bG5tdHVb%2BSBW9lcaq2uQP7VwjpRpjjqQWJ3uHs8qKEe%2BCuw2QulGVCa%2Fb9f%2FC3bAXsSGdtty9P%2F2dQJjSCITpDQBlS6gQCKM6g%2BtKMx5Y%2Bv5zJo330mSt8fZyRwfL7GjfHEi9PS1kP3mnwR9NjJe35vr1KTsqp9PrPEGWkpHmWt6SQRv5Mi68jdi6Bu1oHafV8t38zMLlfzhQL%2F8H%3C%2Fdiagram%3E%3Cdiagram%20id%3D%22-orogJ3IejnkKjbWXvhb%22%20name%3D%22simple_exec%22%3E7V1bl5s2EP41Psd9sA9I4vZY727SnibZNmlPs33xYW3ZpsHIB%2FBe8usrAbIRkjFZm4up%2B5CCEDLM6Bu%2BmdFoB%2FBm%2FfI%2BdDerj2SO%2FQHQ5i8DeDsAQLeARf%2FHWl7TFsfU0oZl6M2zTvuGL953nDXybltvjiOhY0yIH3sbsXFGggDPYqHNDUPyLHZbEF%2F81Y27xFLDl5nry61%2Fe%2FN4lbba%2FLVY%2By%2FYW674L%2Bumk15Zu7xz9ibRyp2T51wTvBvAm5CQOD1av9xgnwmPywVs7cmzPrub3NjLz5%2F%2Bsv%2F5gB5H6WDvfuSW3SuEOIjfPHQQ3o8mLplugld0%2Byl2gP7rYoSMdOwn199mAsteNn7lEgzJNphjNoo2gJPnlRfjLxt3xq4%2B0zlD21bx2qdnOj3MhsNhjF8KCjjy9PpOpHQuYrLGcfhK7%2BOjaCjTSzYPDTt79Oe9VqGT%2Fdgqp1GgZR3dbCYtd4PvpUUPMoGphRff%2F%2FLiffu8%2BOOrNvv4p%2FPn%2B4c%2FPozgcdnhOZ2M2SkJ4xVZksD17%2FatE1G6%2Bz4fCNlkMv0Xx%2FFrhix3GxNR4r77iP2JO%2Fu2TIa6IT4J6aWABGx4HMx%2FZiiiLTPfjSJvlja%2B83w%2BwIIEcTa6DrJzPsoAQC35b6faanqkQiDbcIZLpJehKnbDJY5L%2BmXjMUnmJpQ8UULsu7H3JML%2B7DrXJJ1H3nrj4yl%2BwTNZ%2Fb5P7RyuCpuqspXgdRA2wDbHhoAbbpdzsNE5QvKwMcyaJFjB4lxRcwwNR1GD2kKN8jOjd0LnSpHUqxulNLSGVFH2kHkDFm8p72LKcOOEYVExD4Dp01eYPIb0aMmONiN65K6Z3UrOZ2vaSUtG0OjxdEPp0vAn%2Bb7bXz%2BzHis8%2B7bY30E2FE1eOKSievqphHHox01nPUD8AROLkGhgVRbW0WQLy4n02VWMJBVzBUmSppx2ww43IZnhKDou7cedybzfxr4X4I5oAVnGcS2AmrSgtnmt2Dj84sVfc8cPbChKAdKz25ds5OTklZ8E9H2%2F5k9yd7HT%2FW3JGb%2BvbntqVmWIsNVvmwy3h7svsiFUzoYPjIaIGnR9bxkw4kGFiCl8JgwEHnVof84urL35PJ0sOPK%2Bu4%2FJeEwfG%2BIFcfJ6xmRg3JZ5Y5m3nd082Pm4ed2VzOqDMBxpYwozXYAi95MqqyMb%2FXf2OvuhtbGOlOPyIchiEdF5UtTn7iFPULH1v%2BAvCrypxWG2iTfgSMq486mP1Q94WUfhBYF9Gp7OipeyiZTT0OPW8%2BOpFyjMIrtebNQlbYYrsn7cViAobRMR4IhxKmjJRMRW8BC7Ljaoy2EqzAh%2B10IVyLREwdlAZnCNRip0eR7LU5V5TcOic8TcGmolNGYm1DNe0yQNXMwUL2rKBPIUd0xZUU5tDo8clWvj%2B3ypMSVYNRQLLSUFaSuUgcBV7U2oHXUrBK%2FIWbVFAN%2BuufIJXZVRlhFFqNmmYKZHoOu8Ecp2XBl2vNQPJ3BEz9hp%2B8MJrsmYUywol9ZRCwpaS8eoH0cmtknI6uIN6G4%2Bn8OAAsQj%2B921mDwWcAVwzQDuFvNVxMA%2B3fcBv3w6n4UA6WbnGQ%2BfgDlFLkj4LUmkpqwneIw2fQga6Dp%2Feh410NomP3Lihi3iecLDhGTesN9kcZzkCAdPXkiCC89V65oJBSVYUJEmtRThSVSbFuTcyrPrxcMdANJ%2FWcJymqpHscig6CUkvdMR%2BYqDZ9bGgnXbaCgOdtEKBcgWUaXLyyKVCq1t9QG8Los8KSpjVaQk0O4UJYEH0uAXz0l28%2Fn%2F4lPAa1CgGQA73QKwHBTohU8BzxkTuASfAsqMqqc%2BRTER2Xo8FcrhmL67FAiKbp2uGW27FFCOjlxdisoK3XkQHFSwbY8CydTySkiqExKevj2e54WdIiSoG6su%2B692s1tqlytUAhJPk7KUKaayDocXbmGBJS4R1DXFGsHaihVKoa8U%2Bt0BofemeKQYmu6CQmQOczV%2BP2D8qtaOoG5F0ZDshC9CjKUFptSd6JsR1NvHnMJ76%2BJKaUVR904oTSyWVu8k0Ql7pQTz2%2BzK4dLdCiUyoCEjoi4ikQO4LYXiD8zsEwpkUCkytDHQxCV22dmJtWcja2yqhq2%2F9MxqA0W8iHRfOPqQu3KsiHRfN%2FqQv1Z%2FEWlVxB6uWWoLsfKHpz8lbUcr2nQHnFghWj8Mjy9MTuO6hQC7svaH3V5sH8tkrp4g%2FPl3ZioWvO3iug0UvKk%2Ff73bbeQwxahSrdvUdiNlT5nfi8InEWZ7fyR7gkwXzToy55%2F%2FyADi%2FOfneSoOFVS8vp0nZGt1Bj%2Fm%2FJIzTa0gOSRLrlEnRnfapFsXtmdHyd4AVcyS3aZZUlQaPeCoH4QrncSlq5BMrUt7CKg%2FHKri6%2F59xSvjJS1tae0zLufi%2BuOhgAO%2BX37ZnvChOjGo0MCGNTJ4ONuSydalOhrIadnR4O91ZQtvtn52VevXqhOjy%2FEZlRcjLSEaKxYN6czaFHuyXOsGh2svijwSRMPNpftEyCpkKAxFtU%2BzXhEPMl3R%2BuaIQ%2BXsB2iVq8jcvoivzqxlqMGpRqJTrQSeUVNatWQ2dD8cYRtFySkCOY2GI3g5bMMmq6vmx5DNT8m%2BXa2FFmSy0JvQAjgQtMl7SuKS%2FFHnfSWO%2BmuKtXZgwlZZvCHnhfoTwzCOli4hXSz9BqcBkw8MxEHtMWxsW17F7kVlGzEe2o9xTIe4%2F8wcNPqAFxwdERe%2BNLkpo%2Fo7aLRpV%2Fvgb0HFCn51xwOrohoiPHKwsT92FR4Iu%2BcZjyaGOk40rPXbTV5hcWU8tSMTtcp4FBuk9sYVQeWfwyTLaYm%2BSOddESgzVHfGwlHDr9P73xQx4UshJ8WgVPvkBFzJyYl%2F7Kpq4ho2VVCj%2FnU5cd0bEwgPhNlzJhA4on%2FW%2FXAMaifm2SdygqqSkwNLsxtCplwxxLYpSTZRKPuDCj3O3dgFT8JUbb3QaO6Gl6FeEhq75cSjqknTdtGo%2BBMaFRYl9AZ5ZiE4aqnqKZtFnqISeGced7sJKXRCJRPXx2IYWKNMUTXqQ9ctkbgYhi0rRFcoBNSmEJlJdjONDYprb2zVjkxnSmTT05CQOM8B6ZuuPpI549J3%2FwE%3D%3C%2Fdiagram%3E%3Cdiagram%20id%3D%22beHCSEKuuDDrRnGYzYcp%22%20name%3D%22cmd_path%22%3E7Vptc5s4EP41zKQ3kw4vBuyPtpM0d%2BPedcbtnHNfMjLIhlYgTgi%2F5NefBOJVNDiX2CYd%2B4vRIi1on91Hq0WKMQ12nwiIvM%2FYhUjRVXenGDeKrmu6OmJ%2FXLLPJJatZ4I18V3RqRTM%2FScohKqQJr4L41pHijGiflQXOjgMoUNrMkAI3ta7rTCqPzUCaygJ5g5AsvRv36VeJh3qdim%2Fh%2F7ay5%2BsWWLCAcg7i5nEHnDxtiIybhVjSjCm2VWwm0LEjZfb5dv2%2Fu6ftTdNRgv6dPd9Np7NNteZsruXDCmmQGBI%2F7fqP%2BaLxdh0kTUdfE0%2Be8Fye%2FP7tZGp3gCUCHuJudJ9bkDoMnuKJibUw2scAnRbSicEJ6EL%2BWNU1ir7zDCOmFBjwu%2BQ0r1wDpBQzEQeDZC4i8ASoglwfqxTVVOMMGG3Qhxy9TB0x9wRmMRBII59JxPe%2BShXsMIhFdo1XbRzLYpuqOmPyQ80pDB4jBPiwGesJxyDArKG9Jl%2BQh%2B3ZMUpBUyfIA4gJXvWgUAEqL%2Bpey4QAbAu%2BpUgswuB8wswVyXMncB9jLi7S9gjxOKUg7D1fArnEUjtsWVUUUfwZYbdQELh7llTiLuGpX00s0H7Oq9sy2DWVNHFqwSyaR3JfINLyLwiZPIloCtk9F6FjHXB%2FASYm73CXJMwdzxAmOS3iDOlmsrURzYlGG6uFN36N%2BGZwOTL%2BOv9B9ZEvLFkA6w1v8oHuz6Ji9ExJRT%2FuEoVTrm00KIY47LxQfK20pe0bnI%2BDuwvIHHdqlO43sLhtiVzuKUeCVtdwjbHUTY1S%2FsifhkR7MA47jb3sojQvxKK%2FBD2BAZzqHbDkMtOAoOmSdY%2BAY3CnU8XYji%2FfuDXLMvIWje7yq2bfd4I2XwXuQLeqIzizXJY2srHvVfKNg%2BkbLtflH3JzU4Bumb0CnVTAj1bY5tLpoeDZXIAf5%2Bbpw17UONp3ZR5ethC08Oj0fRZoqig6YKaHyp3Omi6wswPNWL%2BtWjaPjBih70KWFsK2BWBkGfB7zzR1ex6hlVkTmfLsIaSqQmkCQmZ7M9vs5kc1%2Bcu%2BGi23Sj4GC30d9qKj3bZ%2Fr9q%2B28cmlf0rAAgF8fZfj1xaIo84H8rDsTP9%2FpO4BZb%2FQAghJ0rTdUHLdUBWfLInuVE%2B6tUB68N8KSmra5QeQYb8ujg0AG0HFYpKTBrVEsKL9XE4Nso5kRVzJt3ztOGNmqQzEBtIZnhSCYZbXC0msR5s6zLZriTl7oJrF95li4T2MPtvNXLZhyaumcA5K9DDgYzImQWnvD48h2AxuJG4Ltu5oQw9p%2FAMtXHzR9hP6TpZMwJI4tXAfdsqEgRX3xGFm%2BjVL%2FUtjHBtfpRtw29xgVC08EYCeVf%2BKwrXfBqFTNvaYJYvMMrcJV3vJd85AjhrA96Fc5aG%2BzNRZwnJnzJbssx%2BJCmUJU8593WScyhKa3hp62T2GddwS91ks6FuXsFH%2FUr5OX9%2By9aKjFHcvCe%2BGPUSLJ1UStJ90D9L5VYo3OXSvIvveehQE05fBNzMJWVEsFj6vl47O0zkkbyKlxroDU%2BQeiNqMuIVIwqfYbZDOwr3cRO4KfPsdU6C9hm4wxjR%2F%2F8vUqXzd7gbdNt%2Bati2yGOrJ76%2FCmOZvaVknmWrb1nMjcG9QMedtvJAuNtDniwZnnkNoO4PLhs3P4H%3C%2Fdiagram%3E%3Cdiagram%20id%3D%22-mKRq0l2F6xpoRqSxReI%22%20name%3D%22built-ins%22%3E7Vpdc6IwFP01zuw%2B2IEgqI9qbbsz3e5OfdjtkxMlQtaQMCH40V%2B%2FAYKIca22VWlXXwyHEMw599xcgjWrFyxuOQz978xFpAYMd1GzrmsAmMBoy68EWWaI0wQZ4HHsqk4FMMDPSIGGQmPsoqjUUTBGBA7L4JhRisaihEHO2bzcbcJI%2Ba4h9JAGDMaQ6Ogv7Ao%2FQ1ugWeB3CHt%2BfmfTURMOYN5ZzSTyocvma5DVr1k9zpjIWsGih0hCXs5LBzzNn6fRNHIeHr37Bf7dfBjUs8FuDrlkNQWOqHj10M931s23uG8%2F1If%2BzBg2po9Gp660nEESK77UXMUyJxC5kk91yLjwmccoJP0C7XIWUxcltzHkUdHnnrFQgqYE%2FyAhlio4YCyYhHwREHWWwBEiXTieeulQPUYYl6coo8nwiLqdJBBKyA0mRN1wwqhQQ5tAHedD1IBlpB%2BJ78miYjtiMR%2BjHdSpqBCQe0js6KfGS2hci0il0S1iARJ8KTtwRKDAs3LYQhX93qpfobBsKJEPENzQBB%2FFmIg6ppGuPCHSpQnhcx8LNAhhSshcJoqyfocxO0NcoMVOLtRZYDSyS5blnDIvjGwadob5aya2nSOx1%2FhYdhkTGEV4XHKMeT7H5On%2FJcdYlXKM2dREf%2BoPtup%2BnwhT1goS7NFECkkhkvx2k%2BjHcnnqqBMBdt0sLFCEn%2BEoHS8hP2SYinQydrdmX79Jtp3BvGnH1Vqsfkxpudtm07pxBVrZlXtLogb7mUxyrQubTCIZG5uare75ehlbF%2BuewLrNallXF71P5IL28b2bT%2BxdvOuYpVU2F7u6XjY1WWvAIZKv7ojLlpe0wrpswSCpVNJjGbkzqYaRyKF1TgfZBNECCy1UuM%2BCURy9XBMdx6gH1E6mc2WXqyegl08tQ6%2Becuz97agXn5ccvH8Obu6Zg9uVysFAN%2BvnKJ9W0fwuOdh0qp91nYt9T2Bf066Uf%2FWnn6OstXT2mZZa4Jx5qb1Y9S1Wtfa0arWcammacyRiTrdXtsN032%2BI6Zevemice%2BPPssFm8WoBzVGn3fuzNXpfojHyYZg0Q87GKNojkY1WVvkRC4IpqkiCsw1dji1bsWBLhnOO9jABLinuDSmuvW81Uq3XF%2BZlB%2F4kqldrC76tp14625V5C4HN6pePVsPeLB%2BbZ8%2Bu%2BlP7f7zaVUCPfxd3hqlJUYH6zSoRaLXP%2FebW1Mu3FYFG9QjcfPN9TALlYfEnlmyzqPgrkNX%2FCw%3D%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

#### Authors
David Gonzalez - [@davidgonzalezfx](https://github.com/davidgonzalezfx)<br>
Nicolas Forero - [@nsforero10](https://github.com/nsforero10)<br>
