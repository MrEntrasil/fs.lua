require("fslua")

local dir = "."
local dir_table = fslua.readdir(dir)

if dir_table then
    for _, file in pairs(dir_table) do
        print(file)
    end
else
    print("Cannot access dir: "..dir)
end
