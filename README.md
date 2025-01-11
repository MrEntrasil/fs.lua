# fstream.lua
## fslua.readfile
Reads the contents of a file using std::ostringstream
### Usage:
```
fslua.readfile(filepath: string) -> string || nil
```
### Example:
```lua
require("fslua")

local filepath = "file.txt"
local content = fslua.readfile(filepath)

if content == nil then
    return print("file not found.")
end

print(("%s's content:"):format(filepath))
print(content)
```
### 🌲🌳 Tree:
```
- main.lua
- fslua.so
- file.txt
```

## fslua.writefile
### Usage:
```
fslua.writefile(filepath: string, content: string) -> boolean || nil
```
### Example:
```lua
require("fslua")

local filepath = "foo.txt"
local success = fslua.writefile(filepath, "bar")
if success == nil then success = false end

print(("success?: %s"):format(tostring(success)))
```
### 🌲🌳 Tree:
```
- main.lua
- fslua.so
- foo.txt
```

## fslua.exists
### Usage:
```
fslua.exists(path: string) -> boolean
```
### Example:
```lua
require("fslua")

local dirpath = "."
local result = fslua.exists(dirpath)
print(("exists? %s"):format(tostring(result)))
```
### 🌲🌳 Tree:
```
- main.lua
- fslua.so
```

## fslua.readdir
### Usage:
```
fslua.readdir(path: string) -> table || nil
```
### Example:
```lua
require("fslua")

local dir = "."
local dir_table = fslua.readdir(dir)

if dir_table then
    for _, file in pairs(dir_table) do
        print(file)
    end
else
    print("Cannot access dir: "..dir)
end
```
### 🌲🌳 Tree:
```
- main.lua
- fslua.so
```

## fslua.getline
Reads the contents of a file using std::getline
### Usage:
```
fslua.getline(path: string) -> table || nil
```
### Example:
```lua
require("fslua")

local dir = fslua.getline("data.txt")
print(type(dir), (function() if dir then return #dir else return nil end end)())
```
### 🌲🌳 Tree:
```
- main.lua
- fslua.so
- data.txt
```

## fslua.writedir
### Usage:
```
fslua.writedir(dirpath: string) -> true || nil
```
### Example:
```lua
require("fslua")

local success = fslua.writedir("XIQUE-XIQUE - BA🚩")
print("success?: ", success)
```
### 🌲🌳 Tree:
```
- main.lua
- fslua.so
--- / XIQUE-XIQUE - BA🚩 \
```

## fslua.sizeof
### Usage:
```
fslua.sizeof(filepath: string) -> number
```
### Example:
```lua
require("fslua")

local b = fslua.sizeof("foo.txt")
print("size(bytes): "..tostring(b))
```
### 🌲🌳 Tree:
```
- main.lua
- fslua.so
- foo.txt
```
