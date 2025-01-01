# fstream.lua
## fslua.readfile
### Usage:
```
fslua.readfile(filename: string) -> string || nil
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
fslua.writefile(filename: string, content: string) -> true || nil
```
### Example:
```lua
require("fslua")

local filepath = "foo.txt"
local success = fslua.writefile(filepath, "bar")
if success == nil then success = false end

print(("success?: "):format(success))
```
### 🌲🌳 Tree:
```
- main.lua
- fslua.so
- foo.txt
```