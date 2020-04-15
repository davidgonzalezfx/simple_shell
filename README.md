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
Go to this link to see the flowchart of our project: [flow chart](https://app.diagrams.net?lightbox=1&highlight=0000ff&layers=1&nav=1&title=shell.drawio#R%3Cmxfile%20pages%3D%225%22%3E%3Cdiagram%20id%3D%22ZPFKSTzHN-5zQBHHbEto%22%20name%3D%22start%22%3E7Vxbc9o4FP41zLAPMJZ85RFIms02TTulnW32JSNAgFtjeW0RIL%2B%2Bki3jixwgxMRKprxgHUuydc75zk2Clj5cbq5CFCw%2BkSn2WlCbblr6RQtCALUe%2B%2BKUbUKxoCDMQ3cqOmWEkfuIBVET1JU7xVGhIyXEo25QJE6I7%2BMJLdBQGJJ1sduMeMWnBmiOJcJogjyZ%2Bq87pYuE6kA7o%2F%2BN3fkifTKwxPqWKO0sVhIt0JSscyT9sqUPQ0JocrXcDLHHmZfy5frmcTlw%2BoA9%2Bdfw44fFP%2F%2BhfieZ7MNzhuyWEGKfnjw1%2Bgg%2BRdePX4KL79F3Ovra%2Ben7HZhM%2FYC8leCXWCvdpgzEU8ZP0SQhXZA58ZF3mVEHIVn5U8wfo7FW1ueGkIARASP%2BxJRuhXKgFSWMtKBLT9w9cn2CDxFZhRO8Z1FCXhSFc0z39BPz8QXmdEVw7wqTJabhlnUIsYeo%2B1BUKCT0cr7rl%2FGeXQj2P0MUmiSK0bf%2B12%2ByPDyPYYfzfb1wKR4FKGbGmsH3JVx9wCHFm718EHd1C3TNZNA6QxTQBG2RQ5NpnYlZ1nvU29Q8HtJbUym9BZIorn2XusjjXOP0MGpBy2MLGoxDdjXnV%2BihBYd8DczCM6IWD9S0hOhx%2Fqc0IA%2F2sF8ewmSAlhG%2FkLsH3cKESUPu5KMl3nVi72cOtJZ5UdUTb1x6n6w39xpyPzZFvHo%2Bi%2Bh3%2B%2F3mRtLUTA9Bg6g2BKa2qSPUZIzrloxxkPrH%2BjVLk1j1CqDm0v2Ru77jUzGDl7QuNmLmuLFNGz5b7498IzeKN7NhcSsdV7MBMY80ILZaBsRoUsyZaO9ydw6JOZPsXUGwSokZqBXgmHKAw16frdedM8Fxy%2BxGFPu4yl%2BMrq%2Bub1kspHUYBS25TYzp8XA2%2Bp7LqXLYt9GXymHs1v311a2ixtg0CsYY9iqMcWp388bYOpcttiXhJWKLGd%2F%2BS2IjS5YCfhmEZIKj6DArx2jyax4z%2F%2FOKeq6Pz8xi09EUYzGwGrWDJ7m759nBGfHpkHgs4uOr07X4wwM6NMbeYKcAaRefcC2oPco%2BNswGasXZUIbg7edKjbnh7ORBtscgysgTxjjMGDrg6HAnyOuLG0t3Ok20CEfuIxrHk3CBBMT1abwAc8DD16dFx%2BlCtwA8ZBz3qr0E3V1NSLxYK192qYJ0h6mjAfQCrDuiebSMxOxfOAeyqYHZdWAv93EKT9GL85HZLOKurSTx3RufrgS6XCVowmjsB2xZJ57SnaaAnVYwFQG2LmfQd5ejvcjOiaJukJ8muP3K%2BmJka11gm2YR2KAeYJcmtbqW%2FVpgBrLgRT2kHMemlChAfkErrP9XvPwcS6ozQ0vXYy%2FU5%2BWGNN5lctMNriehy4PsEjXuyQsoEfKjToRDdxbXKviNeM4oVgc%2BIzCCze4ekyftCNXjNz08o9nb7F77EracXqtfUR1JKYxxyaIS8uXnD2y2dgfIEWW4IMvx6ohI8mxBuVWskBi2HDH2qgok2tkiRkcJb1C3HT86v1WsjiEnuLMQ43bQHa9mswqFViHTBHYxDTKNptMgKFtF9UOcuiFgHwsBtUIZKBuk9xHKwKeAdUqSAqBRCjtemKScP1SBsm17D57mWJhBQymYAbkU4EaIMa4d0anrKxg7gV7RzVgVbsap8DLO2UKnnsTCdchY0wZJPJwLZs2hnw9t%2Bd2q8LRRb56y1WzcexsSX7E%2FlW1F04cYgG13iwmlbVXw7lUPNei6EkZWyeJOWrM5aKp1qJSphrKdGS3ImrMmJMugYs%2BqeCSCLZZvhrRrSCHOI7nTN7WaN1a60wS%2BTtlxURKT9UOtukanw1KOWj5xkhgFMSrTiX4Yom2um8gSjn6O7TglFUtmrLeiLxsIlt6gX5Wa%2BbaSphRetSRNWk%2BDBem8sP57%2FpzJgJJk30cyXKtcbdOqaYsOdvWqLbpXELQc8%2F6J20o%2B4mDcZuhKxW26DN50bybZQfHHUfCGd2bi4LLzxC4MkNS38QJCefPFTo1QY5svhhpn0JVEfQrmw6hX64yNIRfW3ofLNuo8ZAPN4umXl27Fn99Dm29xT0k1rKbpuipYlatl78pDZ2cnst%2FAlPy0%2Bm7acZo%2BI2HI%2BfUf6Je872E37agFfXk3slg1pTii7eCN10vNUjmqpzVdLzXk7X3OaYnNtR3%2BV00EQGtcBmYj5uuUX0spafLqD2Kqq1EGKG52GOA8NevycwDQS38DUBpg69rLBqQrOWtVPBVTztJU%2FIiXdRok4dFbtvPlfTGgnXFjjDWzf6xIpJX974d%2B%2BRs%3D%3C%2Fdiagram%3E%3Cdiagram%20id%3D%22wnPK8H0QMCBDu31KDfzO%22%20name%3D%22test%22%3E7Vxtc5s4EP4t94FpejPpgHj1xzhJe3OTu0snTe9yXzoyyECDEQcitvPrTwJhXoRj3CQGUncyjbRIAnb1SPvsikjq%2BWL1KYaR9wd2UCAB2VlJ6oUEgKIBILEf2VnnElOTc4Eb%2Bw5vVApu%2FEfEhUWz1HdQUmtIMA6IH9WFNg5DZJOaDMYxXtabzXFQv2sEXSQIbmwYiNK%2FfYd4udQCZin%2FDfmuV9xZMSb5lQUsGvM3STzo4GVFpF5K6nmMMclLi9U5CpjyCr0Ay1vLF7Z8%2B%2FvX4Mxyr9efZ%2F%2Be5oN93KfL5hViFJIfHvrrLPxE5tHky%2BfHO2Kf3q4X6fUpN%2B4DDFKuL%2F6uZF0oEDlUn7yKY%2BJhF4cwuCyl0xinoYPYbWRaK9tcYRxRoUKF3xEhaz45YEowFXlkEfCrAZyhYArtezcb6hwHOKaXQhyy4ec4JLyrAni9aCIBVc7%2BUXn%2B5OxxG5bfoTbeLsFpbKMndMWnAYGxi8gT7ZTN3KCgQniBSLym%2FWIUQOI%2F1B8O8tntbtqVFqQFbsQ9DCoLBv2CEiIaNQgoAJl2l55P0E0Es1df0jWgbho%2BHIoJWv2AWkU18FFUQ%2Fmg5yOt6wvGskSpIvMmXgWhuvFKqtOOWOiMhWIl34UFtU8sKIJBffry9KnvQwkYAX3u6SymJZeVbA%2FSsvwrTFf0V9Zc%2FvP26kqYA6WFld3w2c9erwAzXauDrA1lxQZXRZkhv5JRjCPKOqNM7YgyvU%2BUqYJBqxBKSGx78cksnc8lQG8gv5P08%2FDd%2B7cFq9bN66Cwso6w6gwrvSOszD5hNREMend502rTK6b0uh1g4LshLdtUYYiqd8og4FNSdMYvLHzHyU2OEv8RzrLxmO4jTPfI7F30qaRfvATWOLPjN5E2fKpqz%2B1zeisGT%2BUPQDNAHYd5rbOF%2BODXOHcMiiZ4Pk8QEUy4eYZnuCSiT3LE6XNxqsjtE%2BUwQNXb97%2Fm9ubhxSxNRrC1mfWtTVXFrc1q2dms19rZVLMPhKCVT%2F5h3SlLzWt3lSsXKz5yVlkXlZC%2Bb6UTq95Vr5XdslrR72k0otA5Y3GwmuSjz5SY9R4KWs1RoNUU0FpjfMw7pf%2BN2jnViw22QLDWt3OqiBzhuOs9jY8uQAJ9AkkRI41ZXIUDSRYjLNEpLcEFQ0tWp%2B%2F3sGn%2FjTqnAbZPFGDlPNEaO0UERg2FWhsKTeOQKDyGXvZAIeiKwl6DL4q4n%2F10NDGf10%2FyREvmNxkwMxQJ%2FxGdz0fnlhjCgdAJBJv%2BwtTQuhG%2BFcKoa7qw0R2UMCoiI48RSWPmnGxm2IBSoTowG6lQXTdFX%2BGguVCg97H4DId0D2ahszoudKBXVq2I6YdGEojg%2B5Pmulcmhaj8v5Sdo5nWKmOnAFo9Om2YLRRA00RYvxoFULUjrIcAa9CV44Mtvu1hYA1Ejs%2F8lzcV3zaNnuPbhZ9%2FdPy74EF7Jh4avI5PCq2Rz7fkhrVzRPNeL0%2F%2BgBgg%2FeloPNgSzhwXjQfiKcKRkQ%2FTBKKXclDyoaq9eikVH6X0WHZ4KUrNRyldlnF7KUbHVVnt9cizNoYzFZUsrh3AJPFtqZrI3d8zGoDZtV45JxDTGW%2FKMZ3IfTumYm4h8RdRgL6hFbJPRHKeeDBixSjGNko6qHy2QctfKQn8EA3EFFo9gT7p%2FXSneuQIe5ya7kwmej3gqY4h4TOibauz2dVec0Kq6K00VtXmuYl5jJAQO4Xuw8ijo5vTusNZZcUo9oa7DZC6UZUJn9D1%2FxHdsBexQZ%2BgfLY%2FvSW4pTSCW3oDQPmKKQS3qM7gutKMB4u232fS%2BNZM1hpfJO%2FoYJk72jdfpN6eFvJHftGAjibGwFvz9%2FqUHX%2FT6XWe9MrISHMtb8mKjXwZF74wbF2DXmgdp9Xye%2FvcwuVfLVAv%2Fwc%3D%3C%2Fdiagram%3E%3Cdiagram%20id%3D%22-orogJ3IejnkKjbWXvhb%22%20name%3D%22simple_exec%22%3E7Vxdc9o6EP01zKQP6diWsc1jIbR9SJu26Z2b3JeMMQLUCMtjiwD99VeyZbBZJ5AEEB%2FuQyqthYz37K7OrmQaqDOefYn9aPSN9TFtWEZ%2F1kBXDcuyDLMp%2FpOSeSYxDdvLJMOY9JVsKbglf3E%2BUEknpI%2BT0kDOGOUkKgsDFoY44CWZH8dsWh42YLR818gfYiC4DXwKpf%2BSPh9lUs9yl%2FKvmAxH%2BZ1Np5VdGfv5YPUkycjvs2lBhLoN1IkZ41lrPOtgKrWX68WaeO2pGXTbHW%2F46%2Fs%2F3n%2FXdu8ym%2Bzzaz6yeIQYh%2FzNU%2FObrzPy%2BGvw884Ivv1u%2Ff5y%2F%2FP6EmVTP%2Fl0ovSlnpXPcwXivtCn6rKYj9iQhT7tLqXtmE3CPpa3MURvOeaasUgITSH8gzmfK%2BPwJ5wJ0YiPqbpK%2FR6mbT94HKZTdRhlsbgUslBOj8P%2BJ2kIQhJQP0lIkAk%2FE5pPMGAhV7OblurnszQsZKT%2FhDx7OPlEK8axRrNqXMImcYBfUKeyFO7HQ8xfGGcuzEc4HmZjzOO5%2BFyMqc%2FJU%2FnL%2BcoBhotxS5BFQ%2BH8CswNgHlCxhHFD3iGAwg%2FpcJVJQ7TEeH4NvJTDUxFuCiDqGbFMcezN2gXaiOPQZ7zUQWhRQzKutOlP5uGGjIq%2BHLT2ZEGm7XXbNNr8mVhndfYOr2mVWOuA3NHJ%2BYmjJR8IjiKRN3nKRsRIDQsh4pHaPdi0RrKFgnlRTwjPI2p4muCIdGlaPljGUPTfjAW8xjpTQzRfogE%2B7j4AExsaUDm%2Boj8Oqx3ELndVjluVwXunF0VA7dj7AhQGwCa6xpoWrC9SDajmAU4SdZru7fwypsJpyTEB4KC7TYPDAXTBNreQ%2BgUOoznd%2BrzaededgS3UN2rWfHi1Vz1TibkOpuSU6PanvYUc20txiFi9cI2RLtgGqK3tAzZmRfN5K5oXbVBVUOKtBoUZOv33dtKI7uWyJQNw6dkGEoshMqwUHBbBmgS%2BPSTujAm%2FX5mgzghf%2F1eOp%2FUfsQEDUgfptluNK%2B2sRKoGom6SWNRmSgi%2BoJTPbtEXBofLdsxS8vEpeK3G4OkZv%2FBMvaTD2GDQSKsYxXFxZd4B7BeTcm1uLNeTg4TsS5N8Jn5s7fOn1Ezr37k%2Fmweuj87ANjehFD%2BQEKYPqXXV4WQVsYjNu5NNiDvukm61SqnSuKWgKR7FRzd2xlHh1XC80uVLFt7qgQL9FhWHA6tSGuaq5qzoOb2WqO16q2N7RbsNqUHmZ510QMEa3Y17PuAHWmtGiCrZoXK9l%2FO8lzryFihCWkhZH6yHH%2BxWlIXFvskUDEkLNUE0jCAgRwRYyzn68iFXKXlwAW3tbPaOmSMdeR9R%2BRFmx4mQK7OyGvDyFvDvg%2FYba2HSGxYVT2%2FBdd%2BhuoWyjCGt1KGOfiyKoJxvHKz%2BlQWzqaneeG06uNEW42gufrWZ6paDxRZkNie3b5UZvovZyy2fegR06o3ojQ5sFbma8GdqO83Z%2Ba%2F6%2FehTOfgGU9ubwUgByx%2BlMfvFOsJe0l0CkUD23FL3Ed70cCCJ%2FKyE5MXpepNR95bCtIWDp9IzMIjPx1p50Q756FGxWaTW7HZZO8MDBeAMfUJv1i4Qfa3cK71w%2FqDrenobMb8fOtUymTJbpJclCc7ZjydlS0w5DU3w3Nnm4eo3gLbbmnG3ZCXoGeWxT3thcCYenaJBXrmyOFxJRaorgxocuCWVgeGlYFzSyzQ2sLAMSQWCBKqM0kstBdVEazJqMQiLV6fQ0LhVr3os9eEAsEKSZ1QvDmhaLZ0JxQ2ZJY1H3kHH7E3fvNZ6xs0NlzGatj3ArvWNy3yr1mAPWT8IX3n%2BQELXcen9oKyW3Hqfs8vKMOSzVLn3Wd0fjLn703DODQ86p992G7o2%2FQ4sa21hGbDDHwQYwyOmIpc4sRCoKff5Soyt0N85QX%2BLlHLqtDdll56Ed3lL41l9YnlD7ah7v8%3D%3C%2Fdiagram%3E%3Cdiagram%20id%3D%22beHCSEKuuDDrRnGYzYcp%22%20name%3D%22cmd_path%22%3E7Vptc5s4EP41zKQ3kw4vBuyPfkma3rh3nXE759yXjAyyoRWIEyK28%2BtPAvEqEtutbZKM8yVokVbWPruPVosUYxxsPhEQeV%2BwC5Giq%2B5GMSaKrmuq2mf%2FuGSbSUy9lwlWxHdFp1Iw859gPlJIE9%2BFca0jxRhRP6oLHRyG0KE1GSAEr%2BvdlhjVZ43ACkqCmQOQLP3Hd6mXSfu6XcrvoL%2Fy8pk1a5C9CUDeWawk9oCL1xWRcaMYY4IxzZ6CzRgibrzcLt%2FXd7f%2FrrxxMpjTp9sf0%2BF0%2BnidKbs9ZEixBAJD%2Bsuq%2F5zN50PTRda49y354gWL9eTztZGpfgQoEfYSa6Xb3IDQZfYUTUyoh1c4BOimlI4ITkIX8mlU1ir7TDGOmFBjwh%2BQ0q1wDpBQzEQeDZB4i8ACohFwfq5SVWOMMGGvQhxy9TB0h9wRmMRBII59JxPe%2BihXsMQhFdo1XbRzLYpuqOkfk2eL4ytqOMcOy4p%2BMU6IA18wp%2FAUCsgK0hf6aYX7sLiDOICUbNk4AhGg%2FmP9xwERAKuiXwkyexA4H4C5KmHuBO5DxN1dwh4hFqcchLXnUziLQLr8NaOKOoJCJSQUbn7BtLIphBbD0j6amaZtnVfWZTBrqujiVQLZtE5kvt4lZI4ZMvmesCtk9C5Dxrpg3gXmZpeYazJNeoAwyR8RZ0o1lakPbAUwfLxSdOu%2FhGcCo6%2FDb3cfWBPxxoINsFb8KR%2Fs%2BiQuRseUUPzzKlU45tJCi2IMy8YHydtKX9J2k%2FNhsJ%2BAxHWrTuF6C4fblszhlnoibHUJ2xxH2dQs7Yv4Y0SwA%2BN4t7kXRYT%2BnVDkh%2FCVwGD21d0w5LKzwKBpkrXPQKNw49O5GM6f7%2FkzyzKy1mRTeTXZ5o2QrXeeK%2BCNyijeLIelrXzcu6Fsc0%2FKtjul7Etu1gnomtEl6qYEerbHNrdMDweLZA%2F%2B7pqnDbtX42ndlHm630LT%2FZPRdCdRVNB0Qc33lTc7aLrCzPc1Yn7nNG3vGbH9LgPWlgJ2SSDkWfAbT3Q1u55hFZlTZxlWXzI1gTQhIZP99X06leO664KPZtuNgo%2FRQn%2Fnrfhol%2BP%2FcY%2F%2Fxr55RbcFALk4zs7riUNT5AH%2Ft%2BRAPH%2FWdwK3OOoHACHsXGmq3mupDsiSBzaXE22vUh28NsCTmra6QmUONuTBwaEDaDmsUlJg1qiWFA7VxNB6VMyRqpiTN87ThjZokExPbSGZ%2FkAmGa13sppEt1nW5TB8AIHtfTDqNM%2FSZQK7v5m1etmUQ1P3DID8VcjBYDaDzMIjHoe%2BA9BQvAh8182cEMb%2BE1ik%2Brj5I%2ByHNF2MOWJkcYyAF1%2BHxSRK8U22CukLUfUsE1yrH3Xb0GtcIKbcGyOh%2FCtfdaULXi5j5hxNEIvf8Bu4yifeSz5yjnDOrj50lo%2B0wd7cxHliwrfsthyDD2kKVclz3mydxOyb0h5%2B3jqJ3ekOfqmTHBDy%2FX138EGnIS%2Bf399pqcQcyMF75o9RA8nWRa0kPQO9%2FlKJNei6VJJ%2F6e2GAjVl%2F0PM3lRWSgSPqa%2BIx347I2kkr8K1elrjE4TeiLqMN8Wo0meYzcC20k2cBJ6dx1brLGCbjTuMO%2Frnv6t02ewXHDfdlr8qtl3iyOqpL9%2FiaGZfKZln2dpbJnOjV7%2FgYbfdLDCOc8GDNcsrtxnE5cVl4%2BZ%2F%3C%2Fdiagram%3E%3Cdiagram%20id%3D%22-mKRq0l2F6xpoRqSxReI%22%20name%3D%22built-ins%22%3E7Vrdk5owEP9rnGkfvCEgqI%2Fqeb3OXK%2Bd86G9JydKhNSQMCH49dc3QBAx3ul9WGhPX0yWZWP2t7%2FdJdiwBsHqC4eh%2F425iDRMw101rOuGaQLD6MivRLLOJLbZygQex65SKgQjvEH5nUoaYxdFJUXBGBE4LAunjFI0FSUZ5Jwty2ozRsqrhtBDmmA0hUSX%2FsSu8DNpx2wX8luEPT9fGTjd7EoAc2W1k8iHLlvuiKxhwxpwxkQ2ClYDRBLn5X7pmY%2FLzTyaR879g3e3wr%2Fa96NmZuzmJbdst8ARFa82vbm1br7GQ%2Fu%2BOfYXxrg1fzB6TTMzvYAkVv5SexXr3IHIlf5UU8aFzzxGIRkW0j5nMXVRsowhZ4XOHWOhFAIp%2FI2EWKvggLFgUuSLgKirBE4Q6cPp3EtNDRhhXF6ijCbmEXV7SSCUJDeYELXgjFGhTANTzXMTDdMy0o%2BUZztLtrMXGUfcqvQiFvMpesaXKkwE5B4Sz%2BiBbexI0iEWIMHX8j6OCBR4Uf5xUEW%2Ft9UrEJYDBfILADc0wCcxJqKJaaQjT4hkaeLwpY8FGoUw3f9SJooyfsom4gKtXuFb3RfKiuWAKzuztC5nlWVBZWAoFX%2BHxrZzJv%2B1%2Fi3CTAmMIjwtcQbUiDN5RTjGGatKzoC2BvrjcHQQ97sEmDJWkGCPJlBIjyHp337CEywLVE9dCLDrZmGBIryBk9Re4vyQYSrSzdj9hn39YtgOEFJVWbVIUdt2AX067p8katO4MlWfcDIkytiPZJM7Kmw2i2Qo7GO2XfP1MHYu1K2Cuu1KqauDPiSypH0o7naOctcBpSqbY1tfLoMDXHaIdEJ%2FwuXIS0ZhU45gkPQq6VwG6kKiYSRwaMqpkX0hWmGhhQr3WTCJo%2BNd0ZsBf2v31G6VeydTb546ht475bL3J6PefF4y8BsycPvEDNytMgObOlU%2FXPMEjMMI7GRg4NQ%2F5zoX%2BlZBX2BXyV%2F92ecslZYu%2Fp9CazoVF9oLUd%2BVqNaJRK2Up5aGOUci5vRwVztOT%2F3GmH76rIdG1cd%2Bdt4o5o2rZWp8%2Brunfrbm3GNOjHwYJsOQsymKTkhiky1RvseCYIpqktwcZx%2BMA0ew5oHs5pztMcK8pLf3TG%2FdU%2FuQSl9cgMvJezWoV3r03tUTL108l3cLgEH9G0fbsMqNY7vy3Ko%2FrX%2FYSlcDNJ5u6gygAVGHvm3vda3Vrfp9LdBbt60Ljfq5UH%2FjfU4Xymnx95XsmKj4E5A1%2FAM%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

#### Authors
David Gonzalez - [@davidgonzalezfx](https://github.com/davidgonzalezfx)<br>
Nicolas Forero - [@nsforero10](https://github.com/nsforero10)<br>