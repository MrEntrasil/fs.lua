require("fslua")

local dirpath = "."
local result = fslua.exists(dirpath)
print(("exists? %s"):format(tostring(result)))
