require("fslua")

local filepath = "foo.txt"
local success = fslua.writefile(filepath, "das")
if success == nil then success = false end

print(("success?: %s"):format(tostring(success)))