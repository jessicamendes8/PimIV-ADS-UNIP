# PimIV-ADS-UNIP
Sistema em C para cadastrar pacientes diagnosticados com covid-19

# PimIV-ADS-UNIP

Sistema em C para cadastrar pacientes diagnosticados com covid-19

No projeto do sistema de cadastro de pacientes empregamos alguns comandos
e variáveis usando a linguagem C e o programa Codeblocks para criação e
compilação do sistema, que será utilizado pelos hospitais para cadastrar os pacientes
que forem diagnosticados com covid-19 e necessitam de acompanhamento e
monitoramento. Os profissionais da saúde devem realizar o login no sistema
(informando o usuário e a senha) e informar os dados pessoais do paciente, como
Nome, CPF, Telefone, Endereço (Rua, Numero, Bairro, Cidade, Estado e CEP), Data
de Nascimento e E-mail, data do diagnóstico e comorbidade do paciente que serão
salvos em um Arquivo txt (a principal vantagem de um arquivo é que as informações
armazenadas podem ser consultadas a qualquer momento).
Principais comandos usados na construção dos menus consistiram no
comando “do while” na construção dos menus, e o comando “switch case” usado na
sua estrutura, o “If else” comando de decisão, usado para saber se o paciente tem ou
não comorbidades. Exemplo no algoritmo: "S” ou “N”.
O “Typedef struct” e “Struct” foi usado para definir e armazenar os diversos dados dos
campos do cadastro, outra vantagem é a opção de atribuir os dados de
uma struct para outra, com um simples comando de atribuição, e para os diferentes
tipos de dados utilizamos “int” e “char”. Após o cadastro, o sistema calcula a idade e
verificar se o paciente possui alguma comorbidade e se pertence ao grupo de risco
(maiores de 65 anos). Caso o paciente pertença ao grupo de risco o sistema salvará
a informação em um arquivo de texto (txt), contendo CEP e a idade do paciente, para
que essa informação possa ser enviada para a central da Secretaria da Saúde da
cidade, e de forma geral as informações dos pacientes vão ser salvos em arquivo
binário.

## Usuário e senha padrão
Login: admin

Senha: 1234
