# Introdução

O nosso objetivo neste curso é que você entenda o funcionamento e implementação básica das estruturas de dados mais elementares: os vetores, as listas, as filas e as pilhas. Além disso, através do entendimento do funcionamento interno destas estruturas, nos tornaremos aptos a julgar de maneira correta quando cada uma destas estruturas deve ser utilizada.

# O que são estruturas de dados?

Uma estrutura de dados é uma maneira de armazenar e relacionar conjuntos de informações. Imagine, por exemplo, que você precise guardar a lista com o nome de seus amigos. Para armazenar estes dados de maneira integrada e em conjunto (afinal, estamos falando de uma lista), precisamos dispor estes dados de maneira “amarrada” uns aos outros. Para “amarrar” estes dados na memória e os armazenar como um conjunto propriamente dito, nós precisamos dispor estas informações em determinadas estruturas que repliquem este comportamento de conjunto. Essa parece ser uma tarefa trivial, mas não é: além de termos que dispor os elementos de maneira “amarrada” na memória, temos que cuidar para que operações de inserção e exclusão não deturpem a disposição dos elementos dentro da memória, descaracterizando o conjunto. A estas estruturas que nos permitem fazer essa amarração das informações, nós damos o nome de estruturas de dados.

Existem várias implementações de estruturas de dados diferentes. Cada uma destas estruturas é mais adequada para determinadas situações: algumas são boas para “varrermos” as informações em seu interior, mas são lentas para se fazer a inclusão e/ou remoção de informações; outras apresentam o caminho inverso, sendo lentas para a varredura, mas eficientes para a inserção/remoção de informações. Por isso, é de suma importância que saibamos como cada estrutura funciona internamente e saibamos seus pontos fortes e fracos: a simples utilização correta de uma estrutura de dados dentro de um contexto, pode fazer com que a performance e a manutenibilidade do software sejam melhorados.

# Preparação do ambiente de desenvolvimento

Antes de continuarmos, nós precisamos instalar alguns elementos em nossa máquina: O *Java* *Development* *Kit* (mais conhecido como JDK) e uma IDE para trabalharmos, que será o nosso editor de código integrado com o compilador e todas as ferramentas necessárias para desenvolvermos uma aplicação utilizando o Java.

Neste curso, nós utilizaremos o Eclipse como IDE.

### Instalação do Java Development Kit

O primeiro passo para desenvolver programas em Java consiste em obter o Kit de Desenvolvimento Java. Esse kit é gratuito e o download pode ser feito em: [Java Downloads | Oracle](https://www.oracle.com/technetwork/java/javase/downloads/jdk11-downloads-5066655.html). Nós utilizaremos o JDK 11 neste curso.

Na página que for carregada, clique no link **Java Platform (JDK) 1****1**:

Na página carregada, clique em **Accept** **License** **Agreement** para liberar os links para download:

![](https://d2v0x26thbzlwf.cloudfront.net/prod/344/img/rId4hyifqv2f.puf.png)

Para iniciar o download, clique no link correspondente ao seu sistema operacional.

Após efetuar o download, clique duas vezes no arquivo baixado para iniciar a instalação. O instalador do JDK usa o tradicional processo *Next >; Next >* *Finish*, sendo que o mesmo já se responsabiliza por realizar as devidas configurações na máquina.

### Fazendo a instalação do Eclipse

O Eclipse é um ambiente integrado de desenvolvimento gratuito que permite personalizar totalmente o ambiente de acordo com o projeto que está sendo desenvolvido, seja para plataforma Web ou Desktop. A principal empresa envolvida no desenvolvimento desta IDE é a IBM, mas existem várias empresas comprometidas com o Eclipse (como a JBoss, etc.). O Eclipse pode ainda ter suas funcionalidades estendidas, já que permite a instalação de plugins que trabalham integrados a ele, adicionando as mais variadas funcionalidades.

A maneira mais simples para instalarmos o Eclipse, independente da plataforma, é através do instalador multiplataforma. Para obter este instalador, acesse a página de download do Eclipse em: [](http://www.eclipse.org/downloads/packages/)http://www.eclipse.org/downloads/packages/ Logo no início, o instalador será oferecido:

![](https://d2v0x26thbzlwf.cloudfront.net/prod/344/img/rId5n2iezm1j.laa.png)

Clique no link relativo à versão do seu sistema operacional (na imagem acima, 64 bit). Você será redirecionado para a página de download do instalador:

![](https://d2v0x26thbzlwf.cloudfront.net/prod/344/img/rId6sk350ie3.irh.png)

Clique no botão **Download** e aguarde o processo de download.

Após o download, clique sobre o arquivo que foi baixado para que o instalador seja iniciado.

![](https://d2v0x26thbzlwf.cloudfront.net/prod/344/img/rId7xbuqrmgf.5gw.png)

Na página inicial do instalador, selecione a opção “*Eclipse for Java EE* *Developers*”. Esta versão do Eclipse irá atender toda a trilha de Java.

Após a seleção, será solicitada a confirmação do local de instalação. Recomendamos que o local padrão seja utilizado.

![](https://d2v0x26thbzlwf.cloudfront.net/prod/344/img/rId8r4zlu2qr.kls.png)

Sendo assim, basta clicarmos no botão “Install” e aguardarmos o término do processo de instalação
