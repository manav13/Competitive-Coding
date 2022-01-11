// Name - Stars and Bars

import java.util.*;
class GFG {
  public static List < Integer > starsAndBars(String s, List < Integer > startIndex, List < Integer > endIndex) {
    List < Integer > out = new ArrayList < Integer > ();
    for (int i = 0; i < startIndex.size(); i++) {
      //Get the two Indices into start,end
      int x = startIndex.get(i);
      int y = endIndex.get(i);

      //BarsCount to know if we have found two bars or not

      int startBarIndex = -1, endBarIndex = -1;
      for (int j = x - 1; j < y; j++) {
        if (s.charAt(j) == '|') {
          startBarIndex = j;
          break;
        }
      }
      for (int j = y - 1; j >= x - 1; j--) {
        if (s.charAt(j) == '|') {
          endBarIndex = j;
          break;
        }
      }

      if (startBarIndex == -1 || endBarIndex == -1 || startBarIndex == endBarIndex) {
        //No Stars are there between any 2 bars in the given range
        out.add(0);
      } else {
        //Count the bars
        int barsCount = 0;
        for (int j = x - 1; j < y; j++) {
          if (s.charAt(j) == '|') {
            barsCount++;
          }
        }

        int starsCount = (endBarIndex - startBarIndex + 1) - barsCount;
        // System.out.println(startBarIndex+"-->"+endBarIndex+"-->"+barsCount);
        out.add(starsCount);
      }
    }
    return out;
  }
}


  