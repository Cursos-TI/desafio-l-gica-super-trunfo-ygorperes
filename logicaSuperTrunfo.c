import random

# Definir a classe Carta
class Carta:
    def __init__(self, nome, populacao, area, pib, densidade_populacional, pib_per_capita):
        self.nome = nome
        self.populacao = populacao
        self.area = area
        self.pib = pib
        self.densidade_populacional = densidade_populacional
        self.pib_per_capita = pib_per_capita

    def __str__(self):
        return f"{self.nome}\nPopulação: {self.populacao} \nÁrea: {self.area} km² \nPIB: {self.pib} bilhões\nDensidade Populacional: {self.densidade_populacional} hab/km²\nPIB per Capita: {self.pib_per_capita}"

# Definir as cartas (Exemplo de países)
cartas = [
    Carta("Brasil", 213993437, 8515767, 2055, 24.8, 9547),
    Carta("EUA", 331002651, 9833520, 21433, 34.2, 64794),
    Carta("China", 1439323776, 9596961, 14723, 150, 10206),
    Carta("Índia", 1380004385, 3287263, 2875, 419, 2084),
    Carta("Alemanha", 83783942, 357022, 3845, 232, 45876)
]

# Função para calcular a densidade populacional
def calcular_densidade_populacional(populacao, area):
    return populacao / area

# Função para calcular o PIB per capita
def calcular_pib_per_capita(pib, populacao):
    return pib * 1e9 / populacao  # PIB em reais e população em número total

# Função para jogar uma rodada
def jogar_rodada(jogador1, jogador2, atributo):
    atributo_valor1 = getattr(jogador1, atributo)
    atributo_valor2 = getattr(jogador2, atributo)

    print(f"\nRodada: {jogador1.nome} vs {jogador2.nome}")
    print(f"Atributo escolhido: {atributo.capitalize()}")
    print(f"{jogador1.nome} tem {atributo}: {atributo_valor1}")
    print(f"{jogador2.nome} tem {atributo}: {atributo_valor2}")

    if atributo_valor1 > atributo_valor2:
        print(f"{jogador1.nome} venceu a rodada!")
        return jogador1
    elif atributo_valor2 > atributo_valor1:
        print(f"{jogador2.nome} venceu a rodada!")
        return jogador2
    else:
        print("Empate!")
        return None

# Função para escolher um atributo
def escolher_atributo():
    atributos = ['populacao', 'area', 'pib', 'densidade_populacional', 'pib_per_capita']
    print("\nEscolha um atributo para a rodada:")
    for i, atributo in enumerate(atributos):
        print(f"{i+1}. {atributo.capitalize()}")
    escolha = int(input("Digite o número do atributo escolhido: ")) - 1
    return atributos[escolha]

# Função principal do jogo
def jogo_super_trunfo():
    jogador1 = random.choice(cartas)
    jogador2 = random.choice(cartas)

    print("Jogo Super Trunfo!\n")
    print(f"{jogador1.nome} vs {jogador2.nome}")
    print("\nEscolha um atributo para competir entre as cartas!")
    
    while True:
        atributo = escolher_atributo()
        vencedor = jogar_rodada(jogador1, jogador2, atributo)

        if vencedor:
            print(f"\nO vencedor da rodada é {vencedor.nome}!")
            break

        jogar_novamente = input("\nGostaria de jogar outra rodada? (s/n): ").lower()
        if jogar_novamente != 's':
            print("Fim de jogo!")
            break

# Chama a função para rodar o jogo
jogo_super_trunfo()
