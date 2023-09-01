package recursividade;

public class Permutacao {
    int quant;
    Permutacao() {
        quant = 0;
    }

    public void permutacaoString(String inicioString, String finalString) {
        if (finalString.length() <= 1) {
            System.out.println(inicioString + finalString);
            quant++;
        }
		else
        {
            for (int i = 0; i < finalString.length(); i++) {
                try {
                    String novaString = finalString.substring(0, i) + finalString.substring(i + 1);
                    permutacaoString(inicioString + finalString.charAt(i), novaString);

                } catch (StringIndexOutOfBoundsException erro) {
                    erro.printStackTrace();
                }

            }
        }
    }
}
