# Additional Python codes


### List Manipulation

```python
# Add
ls.append(item)
ls[key] = value
ls.extend([item1, item2]) # Return a list

# Remove
ls.remove(item) # Can't be assigned as a new variable directly

# Sort
sorted(ls)

# List to Strings
', '.join(ls)

# Zip
ls_a = ['a','b','c']
ls_b = [1, 2, 3]
zip(ls_a, ls_b)

>>> [['a', 1], ['b', 2], ['c', 3]]

# One line function
filter(function, ls)
filter(lambda x: x+1, [1,2,3])

>>> 2,3,6

# Remove Duplicates
ls = ["a", "b", "a", "c", "c"]
ls = list(dict.fromkeys(ls))

>>> ["a", "b", "c"]
```


### String Manipulation
```python
str = 'Transform_MatchMove4'

# Removing letter/numbers
str.rstrip('0123456789') # Right strip
str.lstrip('0123456789') # Left strip
str.strip('0123456789') # Both side strip

>>> 'Transform_MatchMove'

# Checking starting string
str.startswith('Transform')

>>> True

# Spliting String
str.split('_')

>>> ['Transform', 'MatchMove4']

# String Replacement
str = str.replace('Transform', 'NoOp')
>>> 'NoOp_Matchmove4'
```


### Ternary Operators
```Python
# var
condition = True

# method 1
x = 1 if condition else 0
print x

>>> 1

# method 2
x = (0, 1)[condition]
print x

>>> 1

# method 3
x = condition or "something else"
print x

>>> 1

# method 4
'statement' if condition else 'statement'

```

### Loop with multiple lists
```python
# enumerate(list, start_number)
ls = ['potato', 'cabbage', 'burrito']

for item, idx in enumerate(ls, 1):
	print "%s: %s" % (item, idx)

>>>'potato': 1
>>>'cabbage': 2
>>>'burrito': 3


# zip(list_1, list_2, ...)
ls_a = ['potato', 'cabbage', 'burrito']
ls_b = [1, 2, 3]

for a, b in zip(ls_a, ls_b)
	print "%s: %s" % (a, b)

>>>'potato': 1
>>>'cabbage': 2
>>>'burrito': 3

```

### Unpacking
```python

a, b, *c = (1, 2, 3, 4, 5)
print a
print b
print c

>>>1
>>>2
>>>[3, 4, 5]

```

### name & main

```python

if __name__ == '__main__':
	# module being directly ran
else
	# module not being directly ran, but ran as an import

```

- if run directly, variable `__name__` will be `__main__`;
- if run imported, variable `__name__` will be the **module name**.

###### Example
`main_module.py` contains `import_module.py`

`import_module.py`
```python
def main():
	print __name__
print main()

>>>__main__ # When run standalone
```
`main_module.py`
```Python
import import_module

>>> 'import_module' # When run inside main_module
```


### Color Conversion
```python
# Source: http://code.activestate.com/recipes/576919-python-rgb-and-hsv-conversion/

import math

def hsv2rgb(h, s, v):
	'''
	h: 0~360
	s: 0~1
	v: 0~1
	'''
    h = float(h)
    s = float(s)
    v = float(v)
    h60 = h / 60.0
    h60f = math.floor(h60)
    hi = int(h60f) % 6
    f = h60 - h60f
    p = v * (1 - s)
    q = v * (1 - f * s)
    t = v * (1 - (1 - f) * s)
    r, g, b = 0, 0, 0
    if hi == 0: r, g, b = v, t, p
    elif hi == 1: r, g, b = q, v, p
    elif hi == 2: r, g, b = p, v, t
    elif hi == 3: r, g, b = p, q, v
    elif hi == 4: r, g, b = t, p, v
    elif hi == 5: r, g, b = v, p, q
    r, g, b = int(r * 255), int(g * 255), int(b * 255)
    return r, g, b #r,g,b: 0~255



def rgb2hsv(r, g, b):
	'''
	r,g,b: 0~255
	'''
    r, g, b = r/255.0, g/255.0, b/255.0
    mx = max(r, g, b)
    mn = min(r, g, b)
    df = mx-mn
    if mx == mn:
        h = 0
    elif mx == r:
        h = (60 * ((g-b)/df) + 360) % 360
    elif mx == g:
        h = (60 * ((b-r)/df) + 120) % 360
    elif mx == b:
        h = (60 * ((r-g)/df) + 240) % 360
    if mx == 0:
        s = 0
    else:
        s = df/mx
    v = mx
    return h, s, v #h: 0~360; s,v: 0~1


# Source: https://stackoverflow.com/questions/34472375/linear-to-srgb-conversion
def srgb2lin(s):
    '''1D color conversion where 's' as sRGB sample value'''
    if s <= 0.0404482362771082:
        lin = s / 12.92
    else:
        lin = pow(((s + 0.055) / 1.055), 2.4)
    return lin

def lin2srgb(lin):
    '''1D color conversion where 'lin' as linear sample value'''
    if lin > 0.0031308:
        s = 1.055 * (pow(lin, (1.0 / 2.4))) - 0.055
    else:
        s = 12.92 * lin
    return s
```

### Restart Nuke with Command

```Python
# Source: https://community.foundry.com/discuss/topic/135555/

# Restart
def restartNuke():
    nuke.scriptNew('')
    nuke.modified(False)
    nuke.scriptExit()

# Reload
import myModule
# make changes to the module
myModule = reload(myModule)

```
