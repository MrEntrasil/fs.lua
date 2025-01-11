require("fslua")

local dir = fslua.getline("foo.txt")
print(type(dir), (function() if dir then return #dir else return nil end end)())
