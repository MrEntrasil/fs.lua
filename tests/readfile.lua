require("fslua")

local filepath = "file.txt"
local content = fslua.readfile(filepath)

if content == nil then
    return print("file not found.")
end

print(("%s's content:"):format(filepath))
print(content)
