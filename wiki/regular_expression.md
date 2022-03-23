# Regular Expression
It gives you a clear and precise control over what is matched and what isn't 
In the linux we always use the regular to match the expression.
## The basic usage 
|The character|The meaning|
|-|-|
|.|Any character is required|
|a|The character `a` is required|
|[abc]|Ang character in the [abc] is required|
|[a-f]|Ang character in range a to f is requied|
|a?|The character a is optinal|
|a\*|The zero or more character a are required|
|a+|one or more character of a are required|
|^|The start of input is required|
|$|The end of input is required|
|\\|If you wants to match a meaning character in the regex, you can use it|
|\d|equal to the [0-9] |
|.|Any one character except newline|
|\w|Any one word or non-word character|

## The example 
If the regex is `[0-9]+` 

If the string is abx1233_0, the matched part will be 1233 0

## code 
```python
>>> import re
>>> re.findall(r'[0-9]+',abc123xx)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'abc123xx' is not defined
>>> re.findall(r'[0-9]+','abc123xx')
['123']
>>> re.findall(r'[0-9]+','abc123xx222')
['123', '222']
>>> re.findall(r'\d+','abc123xx222')
['123', '222']
>>>
```


