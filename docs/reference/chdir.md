## fslua.chdir
cd, just cd
### Usage
```lua
fslua.chdir(path: string) -> nil
```
### Example
```lua
local fslua = require("fslua")
fslua.chdir("src")
fslua.writefile("a", "a")
```
### 🌲🌳 Tree
```
- main.lua
-- src
```
