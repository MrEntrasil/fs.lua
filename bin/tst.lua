require("fslua")
print(type(fslua.readdir))

local dirpath = "."
local dir = fslua.readdir(".")

for i, v in pairs(dir) do
    print(i, v)
end
