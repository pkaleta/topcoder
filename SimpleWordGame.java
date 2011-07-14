import java.util.*;

public class SimpleWordGame {
	public int points(String[] player, String[] dictionary) {
        int result = 0;
        String[] counted = new String[51];
        int size = 0;
        for (int i = 0; i < dictionary.length; ++i) {
            for (int j = 0; j < player.length; ++j) {
                if (dictionary[i].equals(player[j])) {
                    boolean flag = false;
                    for (int k = 0; k < size; ++k) {
                        if (dictionary[i].equals(counted[k])) {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) {
                        result += dictionary[i].length() * dictionary[i].length();
                        counted[size++] = dictionary[i];
                    }
                }
            }
        }
        return result;
	}
}
