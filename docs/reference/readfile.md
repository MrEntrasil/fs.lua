## fslua.readfile
Reads the contents of a file using std::ostringstream
### Usage
```lua
fslua.readfile(filepath: string) -> string || nil
```
### Example
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
### 🌲🌳 Tree
```
- main.lua
- fslua.so
- file.txt
```
