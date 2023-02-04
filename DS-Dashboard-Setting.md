---
Title: DS Dashboard Setting
category: pages
layout: post
---

It's kinda dumb, but for some reason you can't get the interface selector to pick Shuffleboard (or anything, really) without an error along the lines of "Can't find script file ______.vbs."
The solution is a bit obscure, but relatively easy.

Aside from launching the dashboard manually (which might not connect) you can set it to launch as default and update the ini file with this...

DashboardCmdLine = "wscript "C:\\Users\\Public\\frc2019\\tools\\SmartDashboard.vbs""

Default ini file is here...
C:\Users\Public\Documents\FRC\FRC DS Data Storage.ini

You can do the same with Shuffleboard (or any dashboard) as well, just point it at the proper .vbs file for the year.

Once you change it, go into the driver station and set Dashboard to 'default'. The others still probably won't work, but default is now shuffleboard or whatever you set it to.