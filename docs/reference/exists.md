## fslua.exists
### Usage
```lua
fslua.exists(path: string) -> boolean
```
### Example
```lua
require("fslua")

local dirpath = "."
local result = fslua.exists(dirpath)
print(("exists? %s"):format(tostring(result)))
```
### 🌲🌳 Tree
```
- main.lua
- fslua.so
```
