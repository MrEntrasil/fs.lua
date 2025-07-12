## fslua.getline
Reads the contents of a file using std::getline
### Usage
```lua
fslua.getline(path: string) -> table || nil
```
### Example
```lua
local fslua = require("fslua")

local dir = fslua.getline("data.txt")
print((function() if dir then return #dir else return nil end end)())
```
### 🌲🌳 Tree
```
- main.lua
- fslua.so
- data.txt
```
