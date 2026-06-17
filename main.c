#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int memoria_instavel = 0;
#define TAM_NOME 50
#define TAM_INVENTARIO 5

int pista_delta = 0;

// =========================
// PROTOTIPOS
// =========================
void pesquisar_sobre();
void refletir_sozinho();
void caminho_em_comum();
void sala_esquecida();
void arquivos_antigos();
void depois_da_sala(int escolha);
void pista_do_passado();
void descoberta_do_professor();
void primeiro_encontro_com_o_grupo();
void confronto_com_funcionario();
void fuga_da_escola();
void revelacao_final();
void final_do_jogo();

char nome[TAM_NOME];
int inventario[TAM_INVENTARIO] = {0};
int visitou_sala = 0;
int fugiu_sala = 0;
int prototipo_encontrado = 0;

// =========================
// FUNCOES AUXILIARES
// =========================
void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void esperar_enter() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int escolher_opcao(int minimo, int maximo)
{
    int escolha;

    while (1)
    {
        printf("\nEscolha: ");
        scanf("%d", &escolha);
        limpar_buffer();

        if (escolha >= minimo && escolha <= maximo)
        {
            return escolha;
        }

        printf("Opcao invalida! Digite uma opcao entre %d e %d.\n", minimo, maximo);
    }
}

void evento_duvida_memoria()
{
    int evento = rand() % 5;

    printf("\n---\n");

    if(evento == 0)
    {
        printf("Voce para por um instante.\n");
        printf("Tem certeza de que isso aconteceu hoje?\n");
        printf("A lembranca parece deslocada.\n");
        memoria_instavel = 1;
    }
    else if(evento == 1)
    {
        printf("A escola parece estranhamente familiar.\n");
        printf("Como se voce ja tivesse caminhado por esses corredores antes.\n");
        memoria_instavel = 1;
    }
    else if(evento == 2)
    {
        printf("Voce encontra a palavra 'DELTA' escrita em um papel qualquer.\n");
        printf("Mas nao se lembra de como ela chegou ali.\n");
        memoria_instavel = 1;
    }
    else if(evento == 3)
    {
        printf("Voce escuta alguem te chamando no corredor...\n");
        printf("Mas nao ha ninguem la.\n");
        memoria_instavel = 1;
    }
    else
    {
        printf("Algo nao bate.\n");
        printf("A sua lembranca do que acabou de acontecer parece diferente da realidade.\n");
        memoria_instavel = 1;
    }

    printf("---\n");
}

// =========================
// INVENTARIO
// =========================
const char* nome_item(int item) {
    switch (item) {
        case 1:  return "Ficha escolar";
        case 2:  return "Anotacao da prova";
        case 3:  return "Chave antiga";
        case 4:  return "Livro antigo";
        case 5:  return "Foto rasgada";
        case 6:  return "Relatorio escolar";
        case 7:  return "Caneta de metal";
        case 8:  return "Pagina rasgada";
        case 9:  return "Medalha antiga";
        case 10: return "Codigo secreto";
        default: return "Item desconhecido";
    }
}

int adicionar_item(int item) {
    for (int i = 0; i < TAM_INVENTARIO; i++) {
        if (inventario[i] == 0) {
            inventario[i] = item;
            return 1;
        }
    }
    return 0;
}

void mostrar_inventario() {
    printf("\n=== MOCHILA ===\n");
    for (int i = 0; i < TAM_INVENTARIO; i++) {
        if (inventario[i] == 0) {
            printf("Slot %d: vazio\n", i + 1);
        } else {
            printf("Slot %d: %s\n", i + 1, nome_item(inventario[i]));
        }
    }
}

int possui_item(int item)
{
    for(int i = 0; i < TAM_INVENTARIO; i++)
    {
        if(inventario[i] == item)
        {
            return 1;
        }
    }
    return 0;
}

// =========================
// HISTORIA - INICIO
// =========================
void introducao() {
    limpar_tela();

    printf("SEJA BEM VINDO AO RPG!\n\n");
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    limpar_tela();

    printf("Ola, %s!\n", nome);
    printf("Prepare-se para a aventura!\n\n");

    printf("Voce e Leon Delta, um professor de matematica dedicado aos alunos.\n");
    printf("Desde jovem, sempre teve facilidade com numeros e padroes.\n");
    printf("Para voce, matematica nunca foi so contas, mas uma forma de entender o mundo.\n");

    esperar_enter();
}

void dia_normal() {
    limpar_tela();

    printf("====================================\n");
    printf("          UM DIA NORMAL\n");
    printf("====================================\n\n");

    printf("Como em qualquer outro dia, voce chega a escola para dar aula.\n");
    printf("Os alunos reclamam da prova de hoje.\n");
    printf("O assunto sera equacoes do segundo grau.\n");

    esperar_enter();
}

void contexto_escola() {
    limpar_tela();

    printf("====================================\n");
    printf("             A ESCOLA\n");
    printf("====================================\n\n");

    printf("A escola onde voce trabalha e considerada a melhor do estado.\n");
    printf("No passado, ela era conhecida mundialmente por formar grandes genios.\n");
    printf("Mas com o passar dos anos, perdeu parte da sua fama internacional.\n");
    printf("Mesmo assim, ainda e vista como uma escola de enorme prestigio.\n");

    esperar_enter();
}

void aplicacao_prova() {
    limpar_tela();

    printf("====================================\n");
    printf("              A PROVA\n");
    printf("====================================\n\n");

    printf("Voce organiza as provas e entrega para os alunos.\n");
    printf("A sala fica em silencio enquanto todos comecam a resolver as questoes.\n");
    printf("Tudo parece ser apenas mais um dia comum.\n");

    esperar_enter();
}

void aluno_misterioso() {
    limpar_tela();

    printf("====================================\n");
    printf("         ALGO ESTRANHO\n");
    printf("====================================\n\n");

    printf("Enquanto corrige as provas, uma delas chama sua atencao.\n");
    printf("A letra e firme, mas o nome no topo da folha nao parece familiar.\n");
    printf("Voce confere a lista de chamada.\n");
    printf("Aquele aluno nao existe.\n\n");

    esperar_enter();

    limpar_tela();

    printf("====================================\n");
    printf("          A RESPOSTA\n");
    printf("====================================\n\n");

    printf("A resposta dizia:\n\n");

    printf("x^2 - 10x + 25 = 0\n\n");

    printf("(x - 5)^2 = 0\n\n");

    printf("x = 5\n\n");

    printf("Uma unica solucao nao significa que nao existam outros caminhos.\n\n");

    printf("As vezes, o problema nao esta na resposta encontrada,\n");
    printf("mas naquilo que foi removido para que ela parecesse completa.\n\n");

    printf("Professor Delta,\n\n");

    printf("se a soma de todas as partes ainda nao forma o todo,\n");
    printf("entao talvez nao seja a conta que esteja errada.\n\n");

    printf("Talvez seja o espaco vazio entre os numeros.\n\n");
    
    esperar_enter();

    limpar_tela();

    printf("Algumas respostas foram apagadas antes que alguem pudesse encontra-las.\n\n");

    printf("Mas uma ausencia bem calculada ainda deixa marcas.\n\n");

    printf("Se voce esta lendo isso...\n\n");

    printf("talvez ja tenha encontrado a primeira pista.\n\n");

    printf("Procure onde os numeros antigos continuam guardados.\n\n");

    printf("A primeira porta nunca foi realmente trancada.\n");

    esperar_enter();
}

void escolha_inicial() {
    int escolha = 0;

    limpar_tela();

    printf("====================================\n");
    printf("          O QUE FAZER?\n");
    printf("====================================\n\n");

    printf("Voce fica confuso com a mensagem.\n");
    printf("O que deseja fazer?\n\n");

    printf("1 - Pesquisar sobre pela escola\n");
    printf("2 - Refletir e tirar suas proprias conclusoes\n");

    escolha = escolher_opcao(1, 2);

    if (escolha == 1) {
        pesquisar_sobre();
    } 
    else {
        refletir_sozinho();
    }
}

void pesquisar_sobre() {
    limpar_tela();

    printf("====================================\n");
    printf("          PESQUISAR SOBRE\n");
    printf("====================================\n\n");

    printf("Voce decide procurar registros antigos na escola.\n");
    printf("Na secretaria, encontra uma ficha escolar incompleta.\n");

    if (adicionar_item(1)) {
        printf("\nItem obtido: %s\n", nome_item(1));
    }

    if (adicionar_item(6)) {
        printf("Item obtido: %s\n", nome_item(6));
    }

    esperar_enter();
    caminho_em_comum();
}

void refletir_sozinho() {
    limpar_tela();

    printf("====================================\n");
    printf("        REFLETIR E ANALISAR\n");
    printf("====================================\n\n");

    printf("Voce analisa a mensagem com calma.\n");
    printf("A escrita parece esconder um padrao.\n");
    printf("Talvez exista um codigo por tras daquelas palavras.\n");

    if (adicionar_item(2)) {
        printf("\nItem obtido: %s\n", nome_item(2));
    }

    if (adicionar_item(8)) {
        printf("Item obtido: %s\n", nome_item(8));
    }

    esperar_enter();
    caminho_em_comum();
}

void caminho_em_comum()
{
    limpar_tela();

    printf("====================================\n");
    printf("        UM LUGAR ESQUECIDO\n");
    printf("====================================\n\n");

    if(memoria_instavel == 1)
    {
        printf("Sua mente ainda parece confusa.\n");
        printf("Algumas lembrancas nao parecem totalmente suas.\n\n");
    }

    printf("Existe uma sala antiga na escola que nao aparece nos mapas atuais.\n");
    printf("Ela parece ter alguma relacao com o aluno misterioso.\n\n");

    printf("Enquanto voce pensa nisso, um detalhe incomoda:\n");
    printf("Voce nao se lembra exatamente de quando ouviu falar dessa sala pela primeira vez.\n\n");

    printf("Como professor, voce tenta racionalizar.\n");
    printf("Mas algo dentro de voce nao aceita uma explicacao simples.\n\n");

    printf("A sensacao e de que essa investigacao ja comecou antes de voce perceber.\n\n");

    if(rand() % 2 == 0)
    {
        printf("\n---\n");
        printf("Por um instante.\n");
        printf("Voce sente que ja esteve exatamente nesse pensamento antes.\n");
        printf("---\n");

        memoria_instavel = 1;
    }

    esperar_enter();
}

// =========================
// FUNCOES FUTURAS (VAZIAS)
// =========================
void descoberta_do_professor() {
}

void pista_do_passado() {
}

void primeiro_encontro_com_o_grupo() {
}

void confronto_com_funcionario() {
}

void fuga_da_escola() {
}

void revelacao_final() {
}

void final_do_jogo() {
}

// =========================
// CONSEQUENCIAS / TRANSICAO
// =========================
void depois_da_sala(int escolha)
{
    limpar_tela();

    printf("====================================\n");
    printf("        CONSEQUENCIAS\n");
    printf("====================================\n\n");

    if(escolha == 1)
    {
        printf("As palavras do PROTOTIPO DELTA ficam na sua mente.\n");
        printf("Algo ali nao era apenas um documento.\n");

        memoria_instavel = 1;
    }
    else if(escolha == 2)
    {
        printf("Voce saiu da sala com mais perguntas do que respostas.\n");
        printf("Mas sua atencao aos detalhes aumentou.\n");
    }
    else
    {
        printf("Mesmo tentando ignorar, a sala continua chamando sua atencao.\n");
        fugiu_sala = 1;
    }

    esperar_enter();

    arquivos_antigos();
}

void arquivos_antigos()
{
    limpar_tela();

    printf("====================================\n");
    printf("          ARQUIVOS ANTIGOS\n");
    printf("====================================\n\n");

    if(pista_delta == 2)
    {
        printf("O documento encontrado na sala nao era apenas um papel esquecido.\n");
        printf("Nos arquivos antigos, o mesmo nome aparece varias vezes.\n\n");

        printf("PROTOTIPO DELTA.\n\n");

        printf("Relatorios antigos mostram que existia um projeto secreto dentro da escola.\n");
        printf("Mas muitas paginas parecem ter sido removidas.\n");
    }

    else if(pista_delta == 1)
    {
        printf("Voce procura pelos registros antigos da escola.\n");
        printf("Algumas fotos e documentos chamam sua atencao.\n\n");

        printf("As imagens mostram uma sala parecida com a que voce encontrou.\n");
        printf("A sensacao de familiaridade aumenta.\n");

        printf("Voce sente que ja esteve naquele lugar antes.\n");
    }

    else
    {
        printf("Mesmo tentando ignorar aquilo, algo continua incomodando.\n");
        printf("Voce decide procurar respostas nos arquivos antigos.\n\n");

        printf("Entre documentos esquecidos, encontra registros incompletos.\n");
        printf("Alguns nomes foram apagados.\n");
        printf("Algumas datas nao fazem sentido.\n");
    }

    esperar_enter();

    pista_do_passado();
}

void sala_esquecida()
{
    int escolha;

    limpar_tela();

    printf("====================================\n");
    printf("          SALA ESQUECIDA\n");
    printf("====================================\n\n");

    if(visitou_sala == 0)
    {
        printf("A sala parece intacta, como se ninguem tivesse entrado ha anos.\n");
    }
    else if(fugiu_sala == 1)
    {
        printf("A sala parece diferente desta vez.\n");
        printf("Alguns documentos estao fora do lugar.\n");
        printf("Como se alguem tivesse mexido depois que voce saiu.\n");
    }
    else
    {
        printf("Voce ja esteve aqui antes.\n");
        printf("Mas a sensacao de que algo esta errado continua.\n");
    }

    visitou_sala = 1;

    printf("\nO que voce deseja fazer?\n\n");

    printf("1 - Procurar documentos imediatamente\n");
    printf("2 - Analisar o ambiente antes de tocar em qualquer coisa\n");
    printf("3 - Sair da sala\n");

    escolha = escolher_opcao(1, 3);

    if(escolha == 1)
    {
        printf("\nVoce comeca a procurar pelos documentos espalhados.\n");
        printf("Algo chama sua atencao no fundo da sala.\n\n");

        printf("Voce encontra uma mesa antiga coberta de poeira.\n");
        printf("Entre varios papeis, um se destaca claramente.\n\n");

        if(prototipo_encontrado == 0)
        {
            printf("No topo esta escrito:\n \t PROTOTIPO DELTA\n\n");
            printf("Algo dentro de voce reage ao ver esse nome.\n\n");
            prototipo_encontrado = 1;
        }
        else
        {
            printf("O documento do PROTOTIPO DELTA ainda esta ali.\n");
            printf("Mas agora voce sente que ja o compreende melhor.\n\n");
        }

        printf("Palavras ainda visiveis no documento:\n");
        printf("- avaliacao\n");
        printf("- desenvolvimento\n");
        printf("- aluno\n");

        pista_delta = 2;

        esperar_enter();
        depois_da_sala(1);
    }

    else if(escolha == 2)
    {
        printf("\nVoce decide observar antes de agir.\n");
        printf("A sala parece comum, mas ha algo estranho no ar.\n\n");

        printf("As paredes possuem marcas quase imperceptiveis.\n");
        printf("Como se algo tivesse sido removido delas.\n\n");

        printf("Voce percebe um padrao estranho nas posicoes dos objetos.\n");
        printf("Nada parece estar realmente fora do lugar.\n");
        printf("Mas tambem nao parece correto.\n");

        if(!possui_item(2))
        {
            printf("\nVoce revisita mentalmente a prova.\n");
            printf("A anotacao parece ganhar um novo significado aqui.\n");

            adicionar_item(2);
            printf("Item obtido: %s\n", nome_item(2));
        }

        pista_delta = 1;

        esperar_enter();
        depois_da_sala(2);
    }

    else
    {
        printf("\nVoce fecha a porta lentamente.\n");
        printf("Mas a sala parece nao querer ser esquecida.\n\n");

        printf("Voce se afasta.\n");
        printf("Mas a sensacao de que algo importante foi deixado para tras nao desaparece.\n");

        fugiu_sala = 1;

        esperar_enter();

        printf("\nDias depois.\n");
        printf("Voce tenta seguir sua rotina normalmente.\n");
        printf("Mas algo esta errado na sua memoria.\n\n");

        evento_duvida_memoria();

        printf("\nA escola parece diferente hoje.\n");
        printf("Como se alguns corredores nao levassem mais aos mesmos lugares.\n");

        esperar_enter();

        pista_delta = 0;
        depois_da_sala(3);
    }
}
void pista_do_passado()
{
    limpar_tela();

    printf("====================================\n");
    printf("          PISTA DO PASSADO\n");
    printf("====================================\n\n");

    printf("Entre os arquivos antigos, um documento chama sua atencao.\n");
    printf("Ele parece ter sido escondido dos outros registros.\n");

    esperar_enter();

    limpar_tela();

    printf("A pasta esta incompleta.\n");
    printf("Algumas paginas foram arrancadas.\n");
    printf("Outras partes parecem ter sido apagadas de proposito.\n\n");

    printf("Mesmo assim, algumas informacoes ainda podem ser lidas...\n");

    esperar_enter();

    limpar_tela();

    printf("====================================\n");
    printf("        DOCUMENTO ENCONTRADO\n");
    printf("====================================\n\n");

    printf("PROTOTIPO DELTA\n\n");

    printf("SUJEITO: [INFORMACAO REMOVIDA]\n");
    printf("IDADE: 17 ANOS\n");
    printf("STATUS: CONCLUIDO\n");
    printf("RESPONSAVEL: Sr. DELTA\n");

    esperar_enter();

    limpar_tela();

    printf("Voce rele o documento algumas vezes.\n");
    printf("Algo naquela informacao parece incomodar voce.\n\n");

    printf("Sr. Delta...\n\n");

    printf("A inicial parece familiar.\n");
    printf("Mas voce nao consegue lembrar exatamente o motivo.\n");

    esperar_enter();

    limpar_tela();

    printf("Voce tenta procurar alguma lembranca relacionada aquilo.\n");
    printf("Uma reuniao.\n");
    printf("Uma conversa.\n");
    printf("Qualquer coisa...\n\n");

    printf("Mas sua mente permanece em silencio.\n");

    esperar_enter();

    limpar_tela();

    printf("Pela primeira vez, uma possibilidade passa pela sua cabeca:\n\n");

    printf("E se voce nao estiver descobrindo algo novo...\n");
    printf("E sim tentando lembrar algo que esqueceu?\n");

    esperar_enter();

    limpar_tela();

    evento_duvida_memoria();

    esperar_enter();

    limpar_tela();

    printf("Voce fecha a pasta lentamente.\n\n");

    printf("Nao existem provas suficientes para tirar uma conclusao.\n");
    printf("Mas existe algo que voce nao consegue ignorar:\n\n");

    printf("O nome Delta nao parece apenas uma coincidencia.\n");

    esperar_enter();

    limpar_tela();

    printf("Uma pergunta permanece na sua mente:\n\n");

    printf("Se o Prototipo Delta tinha um responsavel chamado Sr. Delta...\n");
    printf("quem era essa pessoa?\n\n");

    printf("E por que uma parte de voce sente que ja sabe a resposta?\n");
    printf("Mesmo sem conseguir lembrar...\n");
    printf("Mesmo sem conseguir explicar...\n\n");
    printf("A sensacao de que algo importante foi esquecido continua a incomodar voce.\n");
    esperar_enter();

    descoberta_do_professor();
}
int main() {
    srand(time(NULL));

    introducao();
    dia_normal();
    contexto_escola();
    aplicacao_prova();
    aluno_misterioso();
    escolha_inicial();
    mostrar_inventario();
    

    return 0;
}