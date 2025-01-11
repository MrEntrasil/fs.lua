require("fslua")

local b = fslua.sizeof("foo.txt")
print("size(bytes): "..tostring(b))
