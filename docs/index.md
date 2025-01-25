## Installation instructions
[mrentrasil.github.io/fs.lua/setup](https://mrentrasil.github.io/fs.lua/guide/setup)
## Example
Ok, this is an example of how you can make a mini project with fs.lua. <br>
In this tutorial, you will learn how to make a custom fs module. <br>

### Directories
```
- fs.lua
- fslua.so
- main.lua
```

First, we need to initialize a module. <br>
**fs.lua** <br>
```lua
local fslua = require("fslua")
local module = {}

return module
```

Let's do some basic functions.
```lua
local fslua = require("fslua")
local module = {}

-- read file function
module.read = function(name)
    -- check if arguments exists
    assert(name, "Argument 1 missing.")
    -- calling C function
    local content = fslua.readfile(name)
    -- return value
    if type(content) ~= nil then return content else return "Could not open file(file does not exists)." end
end

-- write file function
module.write = function(name, toWrite)
    -- check if arguments exists
    assert(name, "Argument 1 missing.")
    assert(toWrite, "Argument 2 missing.")
    -- calling C function
    local success = fslua.writefile(name, toWrite)
    -- return value
    return success
end

return module
```

Now, we can use the functions.<br>
**main.lua**<br>
```lua
local fs = require("fs.lua")
local file_content = fs.readfile("fs.lua")
print("file's content: "..file_content)
```

### End

Tutorial finished! You can see the reference guide on the reference's tab.<br>
License: [MIT License](https://mrentrasil.github.io/fs.lua/LICENSE)
