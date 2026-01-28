find . -type f -name "*.sh" -exec basename -s .sh {} +
find .: Inicia a procura no diretório atual.
-type f: Garante que o comando apenas procure ficheiros, ignorando pastas.
-name "*.sh": Filtra apenas os ficheiros que terminam em .sh.
-exec ... {} +: Executa um comando externo sobre os resultados encontrados.
basename -s .sh: O utilitário basename remove o caminho do diretório e o sufixo .sh especificado.

find . -type f -name "*.sh" | sed 's|.*/||; s|\.sh$||'

find . -type f -name '*.sh' -exec basename {} .sh \;
