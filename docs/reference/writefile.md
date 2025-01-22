## fslua.writefile
### Usage
```lua
fslua.writefile(filepath: string, content: string) -> boolean || nil
```
### Example
```lua
require("fslua")

local filepath = "foo.txt"
local success = fslua.writefile(filepath, "bar")
if success == nil then success = false end

print(("success?: %s"):format(tostring(success)))
```
### 🌲🌳 Tree
```
- main.lua
- fslua.so
```
