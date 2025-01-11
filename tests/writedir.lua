require("fslua")
local args = {...}

local success = fslua.writedir(args[1])
print("success?: ", success)
