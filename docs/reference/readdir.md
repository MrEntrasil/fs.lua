## fslua.readdir
### Usage
```lua
fslua.readdir(path: string) -> table || nil
```
### Example
```lua
require("fslua")

local dir = "."
local dir_table = fslua.readdir(dir)

if dir_table then
    for _, file in pairs(dir_table) do
        print(file)
    end
else
    print("Could not access dir: "..dir)
end
```
### 🌲🌳 Tree
```
- main.lua
- fslua.so
```
