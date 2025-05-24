---
tags:
  - Programming
---

# CLI

**CLI** stands for **C**ommand-**L**ine **I**nterface. As its name imples, it is a system that allows humans to interface with computer programs by issuing commands.

## Flags

Command line interfaces typically have options that you can set, typically called flags.

Most linux and windows commands have `--help` flags that allow you to see the full list of available CLI flags. Here is an example for the program `mkdir` (make directory), a program in the [[GNU Coreutils]] that allows users to create folders.

```plain title="$ mkdir --help"
Usage: mkdir [OPTION]... DIRECTORY...
Create the DIRECTORY(ies), if they do not already exist.

Mandatory arguments to long options are mandatory for short options too.
  -m, --mode=MODE   set file mode (as in chmod), not a=rwx - umask
  -p, --parents     no error if existing, make parent directories as needed
  -v, --verbose     print a message for each created directory
  -Z                   set SELinux security context of each created directory
                         to the default type
      --context[=CTX]  like -Z, or if CTX is specified then set the SELinux
                         or SMACK security context to CTX
      --help     display this help and exit
      --version  output version information and exit

GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
Full documentation <https://www.gnu.org/software/coreutils/mkdir>
or available locally via: info '(coreutils) mkdir invocation'
```

As you can see, the `mkdir` command has seven unique flags. There are long form flags, e.g. `--help`, `--version` and also shorter single-character flags such as `-h` and `-p`.
