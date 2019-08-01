void move_pattern() {
  int moving;
  if (!value.patternType) { //Aパターン
    moving = pattern_A[select & 0x0F];
    switch (moving) {
      case 1:
        pattern_A1();
        moving = 0;
        break;

      case 2:
        pattern_A2();
        moving = 0;
        break;

      case 3:
        pattern_A3();
        moving = 0;
        break;

      case 4:
        pattern_A4();
        moving = 0;
        break;

      case 5:
        pattern_A5();
        moving = 0;
        break;

      case 6:
        pattern_A6();
        moving = 0;
        break;

    }
  } else {  //Bパターン
    moving = pattern_B[select & 0x0F];
    switch (moving) {
      case 1:
        pattern_B1();
        moving = 0;
        break;

      case 2:
        pattern_B2();
        moving = 0;
        break;

      case 3:
        pattern_B3();
        moving = 0;
        break;

      case 4:
        pattern_B4();
        moving = 0;
        break;

      case 5:
        pattern_B5();
        moving = 0;
        break;

      case 6:
        pattern_B6();
        moving = 0;
        break;
    }
  }
}
