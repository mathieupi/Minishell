```shell
echo coucou\ \ \ \ chien
coucou    chien
```

```shell
"""echo coucou les monde"""
-bash: echo coucou les monde: command not found
```

```shell
"""echo coucou les monde"""
-bash: echo coucou les monde: command not found
```

```shell
"" "echo" "coucou les monde"
-bash: : command not found
```

```shell
    "echo" "coucou les monde"
coucou les monde
```

```shell
""""'echo'"""" \'\'\'\'
''''
```

```shell
echo $salut

```

```shell
echo "$salut"

```

```shell
echo "\$salut"
$salut
```

```shell
echo \$salut
$salut
```

```shell
echo '$salut'
$salut
```

```shell
""""echo"""" \'\'\'\'
''''
```

```shell
'""""echo""""' \'\'\'\' Chien
-bash: """"echo"""": command not found
```

```shell
'''echo''' \'\'\'\' Chien
'''' Chien
```

```shell
echo           chien
chien
```

```shell
echo   "        chien"
        chien
```

```shell
echo   "        chien           &"
        chien           &
```

```shell
echo   '        chien           &'
        chien           &
```

```shell
echo "\""
"
```
