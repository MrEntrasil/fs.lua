require("fslua")
local args = {...}
local content = fslua.writefile(args[1], args[2])

if content ~= nil then
    print("Conteudo do arquivo: "..fslua.readfile(args[1]))
else
    print("Erro ao ler o arquivo!")
end