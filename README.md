# Dungeon-Crawler
Trabalho de Faculdade: Desenvolvimento de um Jogo em Linguagem C
Este é o README do projeto do jogo desenvolvido como parte de um trabalho de faculdade na disciplina de Programação em C.

Descrição do Projeto
O projeto consiste na implementação de um jogo simples em linguagem C. O jogo escolhido é o clássico Dungeon Crawler,  Um jogo de aventura é um gênero de videogame no qual o jogador assume o papel de protagonista em uma história interativa impulsionada pela exploração e/ou resolução de quebra-cabeças (Rollings & Adams 2003, p. 43). O foco do gênero na história permite que ele se baseie fortemente em outras mídias, literatura e filmes. Muitos jogos de aventura (texto e gráfico) são projetados para um único jogador, já que essa ênfase na história e no personagem dificulta o design multijogador (Hitchens 2002, p. 258). Colossal Cave Adventure é identificado ("The Colossal Cave Adventure page". rickadams.org. Retrieved 31 July 2020.) como o primeiro jogo de aventura, lançado pela primeira vez em 1976, enquanto outras séries de jogos de aventura notáveis incluem Zork, King's Quest, The Secret of Monkey Island e Myst.

Funcionalidades Principais

O jogo é do estilo aventura/puzzle onde o objetivo é o jogador conseguir passar de três fases. Em cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta fechada.

O jogador possui os seguintes comando:

     
W: O jogador movimenta uma unidade para cima;

A: O jogador movimenta uma unidade para esquerda;

S: O jogador movimenta uma unidade para baixo;

D: O jogador movimenta uma unidade para direita;

I: O jogador interage com o objeto que está em cima.

     O jogo possui os seguintes elementos nas fases:
     
&: Símbolo que representa o jogador.

*: Símbolo que representa uma parede, o jogador ao se movimentar não pode passar pela parede.
@: Simbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.

D: Símbolo que representa a porta fechada.

=: Simbolo que representa a porta aberta quando o jogador interage com a chave.

O: Símbolo que representa um botão que o usuário pode interagir, o botão fica no chão e o jogador deve ficar em cima dele para poder interagir.

#: Símbolo que representa um espinho. A fase é reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada três vezes, o jogo volta para o menu principal.

> >: Símbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele é transportado para o outro e vice-versa.

X: Símbolo que representa o monstro nível 1. Esse monstro tem um movimento aleatório para cima, para esquerda, para baixo e para direita. Caso o monstro toque no jogador, a fase é reiniciada.

V: Símbolo que representa o monstro nível 2. Esse monstro tem uma inteligência para seguir o jogador (há várias maneiras de implementar isso). Caso o monstro toque no jogador, a fase é reiniciada.

Historia do jogo:
Era uma vez, o GOAT Casseb se perdeu do seu grande amigo Pedro Girotto em uma trilha.
Ele escuta uma voz vindo de uma caverna escura, um andarilho que passava diz para Casseb que la habitam monstros...
Entao se prepare para enfrenta-los para salvar o Girotto.
Nessa jornada voce encontrara espinhos, botoes e chaves entao tome cuidado com cada passo seu.


Jogoatualizadasso.exe: Arquivo principal que contém a função main() do programa.

jogoversao2.c: Arquivo contendo as funções principais do jogo.

Jogoatualizadasso.h: Arquivo de cabeçalho que contém os protótipos das funções utilizadas.

outros arquivos: Qualquer outro arquivo necessário para o projeto, como bibliotecas adicionais ou arquivos de configuração.


Compilação e Execução

Para compilar e executar o jogo, siga os seguintes passos:

Abra um terminal.

Navegue até o diretório onde os arquivos do projeto estão localizados.

Compile o código fonte utilizando um compilador C compatível, por exemplo:

css

Copy code

gcc main.c Jogoatualizadasso.c

Execute o arquivo executável gerado:

bash

Copy code

Jogoatualizadasso.c



Contribuições
Contribuições são bem-vindas! Se você tiver sugestões de melhorias ou encontrou algum bug no jogo, sinta-se à vontade para abrir uma issue ou enviar um pull request.

Autores

João Felipe da Rocha Soares

Matheus Diniz

João Ricardo
https://github.com/jricass


Licença
Este projeto é licenciado sob a Licença MIT.
