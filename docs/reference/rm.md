## fslua.rm
### Usage
```lua
fslua.rm(path: string) -> boolean
```
### Example
```lua
require("fslua")

local success = fslua.rm("foo.txt")
print(("success?: %s"):format(tostring(success)))
```
### 🌲🌳 Tree
```
- main.lua
- fslua.so
- foo.txt
```
