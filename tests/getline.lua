require("fslua")

local dir = fslua.getline(({...})[1])
print(type(dir), (function() if dir then return #dir else return nil end end)())
