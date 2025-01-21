require("fslua")

local success = fslua.rm("foo.txt")
print(("success?: %s"):format(tostring(success)))
