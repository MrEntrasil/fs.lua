# fstream.lua
## fslua.readfile
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