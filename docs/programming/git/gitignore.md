---
category: pages
layout: default
tags:
    - Git
    - Common Issue
---

# gitignore
A `.gitignore` file is a file which controls which files get upload to our version control system (git). We use it to select the files that we don't want to share, e.g. Compiled Java class files, log files, and JVM crash logs.  
You can view a working `.gitignore` for a typical robot [here](https://github.com/Team2530/RobotCode2023/blob/main/.gitignore).

## `.gitignore` doesn't work

This happens when the files you're trying to ignore have already been committed in the repository.

### How to fix

1. Remove the directories and files you want to be ignored. If some of these aren't autogenerated (you want to keep them), just move them somewhere else temporarily.
2. Create and push a commit to the affected branch of the repository.
3. For any directories or files that you chose to keep, move them back to their original locations.
