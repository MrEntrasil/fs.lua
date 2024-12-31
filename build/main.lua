require("fslua")
local args = {...}
local content = fslua.readfile(args[1])

if content ~= nil then
    print("Conteudo do arquivo: "..content)
else
    print("Erro ao ler o arquivo!")
end