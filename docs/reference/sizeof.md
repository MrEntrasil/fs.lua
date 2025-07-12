## fslua.sizeof
### Usage
```lua
fslua.sizeof(filepath: string) -> number
```
### Example
```lua
local fslua = require("fslua")

local b = fslua.sizeof("foo.txt")
print("size(bytes): "..tostring(b))
```
### 🌲🌳 Tree
```
- main.lua
- fslua.so
- foo.txt
```
