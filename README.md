# BRT
## Renomeação em Massa em C
brt (Bulk Renaming Tool), é um utilitário de linha de comando que permite fazer a renomeação em massa de arquivos.
#
## Funcionalidades:
* `Inserir texto no inicio`
* `Adicionar texto depois de string alvo`
* `Substituir texto antigo por novo texto`
* `Deletar texto em nome de arquivos`
* `Fitrar todas estas operações pela extensão dos arquivos`
#
A ferramenta usa recursividade no diretório alvo
#
## Opções de linha de comando:
`-a|--add` Adiciona string após string alvo

`-i|--insert` Insere string no inicio

`-ae|--add-ext` Adiciona string após string alvo, mas filtra pela extensão

`-ie|--insert-ext` Insere string no inicio, mas filtra pela extensão

`-r|--replace` Substitui antigo por novo após string alvo

`-re|--replace-ext` Substitui antigo por novo após string alvo, mas filtra pela extensão

`-d|--delete` Deleta string no nome dos arquivos

`-de|--delete-ext` Deleta string no nome dos arquivos, mas filtra pela extensão
#
## Dependências:
* `libdirutils`  https://github.com/PedroF37/DirUtils
* `libfileutils`  https://github.com/PedroF37/FileUtils
* `libstrutils`  https://github.com/PedroF37/StrUtils
#
## Instalar/Compilar:
Com arquivo Makefile e todos os fontes em src/:
`$ make && make clean`

Se não quiser usar o Makefile, presumindo que as bibliotecas foram instaladas em diretótórios do sistema como consta nos READMEs:
`clang|gcc -Wall -Wextra --pedantic -std=c99 -ldirutils -lfileutils -lstrutils -o brt brt.c args.c helper.c operations.c`

Depois é so colocar no PATH e dar as permissões necessárias
#
## Exemplos de uso:
`$ brt /home/usuario/Documentos -a curriculum -profissional`

Adiciona '-profissional' a todos os arquivo em Documentos que têm 'curriculum' no nome

`$ brt ~/Imagens -i Férias-de-Verão Minhas-`

Insere antes de 'Férias-de-Verão' 'Minhas-' em todos os arquivos em Imagens com 'Férias-de-Verão' no nome

`$ brt ~/Videos --add-ext Aniversário -2023 mp4`

Adiciona '-2023' depois de 'Aniversário' em todos os arquivos em Videos com 'Aniversário' no nome, mas apenas os que têm a extensão 'mp4'

`$ brt ~/Videos -ie Aniversário Minha-Festa-de- mkv`

Insere antes de 'Aniversário' 'Minha-Festa-de-' em todos os arquivos em Videos com 'Aniversário' no nome, mas apenas os que têm a extensão 'mkv'

`$ brt /home/usuario/Imagens --replace Natal _2021 _2022`

Substitui em Imagens '_2021' por '_2022' em todos os arquivos com 'Natal' no nome

`$ brt ~/Imagens -re Natal _2021 _2022 jpg`

Sustitui em Imagens '_2021' por '_2022' em todos os arquivos com 'Natal' no nome, mas apenas os que têm a extensão 'jpg'

`$ brt ~/Documentos -d curriculum -profissional`

Deleta em Documentos '-profissional' em todos os arquivos com 'curriculum' no nome

`$ brt ~/Documentos --delete-ext curriculum -profissional docx`

 Deleta em Documentos '-profissional' em todos os arquivos com 'curriculum' no nome mas apenas os que têm a extensão 'docx'
