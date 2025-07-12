## fslua.exists
### Usage
```lua
fslua.exists(path: string) -> boolean
```
### Example
```lua
local fslua = require("fslua")

local dirpath = "."
local result = fslua.exists(dirpath)
print(("exists? %s"):format(tostring(result)))
```
### 🌲🌳 Tree
```
- main.lua
- fslua.so
```
