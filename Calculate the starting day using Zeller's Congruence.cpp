  // Segment 5: Calculate the starting day using Zeller's Congruence
    int d = 1, m = (month < 3) ? month + 12 : month, y = (month < 3) ? year - 1 : year;
    int startDay = (d + (13 * (m + 1)) / 5 + y + (y / 4) - (y / 100) + (y / 400)) % 7;
