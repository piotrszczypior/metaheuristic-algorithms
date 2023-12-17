import csv

optimal_cost = 1163

#
#
# errors = [calculate_error(cost) for time, cost in data_list]
#
# # Read the existing data from the CSV file
# existing_data = []
# with open(file_path, mode='r+') as file:
#     reader = csv.reader(file)
#     for row in reader:
#         existing_data.append(row)
#
#
# if len(existing_data) > 0:
#     for i, (first, rounded_sum) in enumerate(zip(data_list, errors)):
#         existing_data[i].append(first[0])
#         existing_data[i].append(rounded_sum)
#
#     with open(file_path, mode='w', newline='') as file:
#         writer = csv.writer(file)
#         writer.writerows(existing_data)
# else:
#     with open(file_path, "w+", newline='') as csvfile:
#         writer = csv.writer(csvfile)
#         for i, (value, s) in enumerate(zip(data_list, errors)):
#             writer.writerow([value[0], s])


def calculate_error(cost: int):
    return round((cost - optimal_cost) / optimal_cost * 100, 1)


data_strings = [
    "[(0,1812),(0.0033045,1806),(0.0034784,1805),(0.003654,1799),(0.0042396,1798),(0.0042631,1789),(0.0043029,1788),(0.0043362,1779),(0.0045102,1778),(0.0048444,1776),(0.0049014,1774),(0.0051356,1773),(0.0057137,1767),(0.0061932,1764),(0.0064626,1762),(0.0071266,1761),(0.0084106,1757),(0.008571,1752),(0.0087132,1747),(0.0088718,1741),(0.0089997,1732),(0.0090055,1726),(0.0097687,1723),(0.0098048,1714),(0.0105256,1712),(0.0107609,1703),(0.0111479,1702),(0.0131935,1701),(0.0145945,1695),(0.0148902,1693),(0.0152345,1692),(0.0153202,1690),(0.0156533,1688),(0.0157568,1678),(0.0159303,1674),(0.019067,1670),(0.0192584,1668),(0.0199132,1657),(0.0199465,1652),(0.0204033,1651),(0.0204917,1643),(0.0206398,1641),(0.0210286,1635),(0.0218046,1634),(0.0227719,1626),(0.022914,1625),(0.0238889,1624),(0.0239504,1622),(0.0244769,1613),(0.0257472,1608),(0.0263685,1607),(0.0275336,1601),(0.0282005,1600),(0.0295008,1597),(0.0318366,1589),(0.0329786,1582),(0.0345005,1581),(0.0346942,1580),(0.0358605,1578),(0.036015,1573),(0.0378289,1572),(0.0383686,1569),(0.0384914,1566),(0.0386282,1565),(0.0390309,1564),(0.0394263,1563),(0.040844,1555),(0.0415484,1553),(0.0418437,1550),(0.0422698,1548),(0.0426183,1547),(0.0428216,1539),(0.0443166,1536),(0.0443736,1535),(0.0498253,1529),(0.0542763,1527),(0.0551982,1518),(0.0577785,1515),(0.0638125,1513),(0.0658058,1512),(0.066274,1510),(0.068401,1509),(0.0687584,1506),(0.0692268,1505),(0.0698905,1504),(0.0717981,1495),(0.0722578,1490),(0.0731536,1489),(0.0739629,1488),(0.0748536,1477),(0.075978,1476),(0.0761022,1468),(0.0870886,1459),(0.0917507,1454),(0.0924684,1453),(0.0927198,1443),(0.0979686,1440),(0.100127,1432),(0.100839,1431),(0.105063,1429),(0.105603,1427),(0.106564,1424),(0.108286,1421),(0.110042,1419),(0.110633,1418),(0.11686,1417),(0.116869,1412),(0.120638,1406),(0.123652,1405),(0.1331,1394),(0.136904,1390),(0.147892,1386),(0.14971,1385),(0.155504,1380),(0.158179,1372),(0.165585,1371),(0.166933,1369),(0.167576,1366),(0.17247,1365),(0.176353,1355),(0.181278,1352),(0.190392,1350),(0.201404,1349),(0.20271,1348),(0.219481,1347),(0.219843,1346),(0.222901,1344),(0.223036,1339),(0.232545,1336),(0.235301,1335),(0.236588,1334),(0.253883,1332),(0.256532,1324),(0.25744,1323),(0.267684,1322),(0.268614,1321),(0.271525,1320),(0.271633,1319),(0.315805,1318),(0.3213,1317),(0.334584,1313),(0.353383,1309),(0.366208,1308),(0.367857,1307),(0.525125,1302),(0.544851,1300),(0.551092,1298),(0.635502,1295),(0.638251,1294),(0.640618,1293),(0.64363,1285),(0.644614,1284),(0.684454,1280),(0.706586,1279),(0.817255,1278),(0.906952,1277),(0.922068,1276),(0.982389,1270),(1.08172,1262),(1.12018,1261),(360, 1195)]",
    "[(0,1812),(0.0146472,1811),(0.0149036,1805),(0.0149613,1799),(0.0153185,1798),(0.0153471,1797),(0.0154306,1795),(0.0156006,1788),(0.0156777,1787),(0.0158629,1785),(0.0160629,1784),(0.0162482,1783),(0.0163672,1778),(0.0163821,1776),(0.0167126,1775),(0.0167386,1774),(0.0168279,1771),(0.016927,1768),(0.0170837,1767),(0.0172036,1766),(0.0174042,1765),(0.0185157,1764),(0.0186856,1763),(0.0188131,1759),(0.0190058,1758),(0.0190406,1757),(0.0191709,1753),(0.0196353,1746),(0.0201269,1742),(0.020236,1741),(0.0203409,1738),(0.0204377,1728),(0.0212342,1719),(0.0214072,1717),(0.0216044,1712),(0.0224874,1711),(0.0228873,1709),(0.0229443,1708),(0.0229463,1707),(0.0234674,1701),(0.0247603,1699),(0.0248069,1687),(0.0251885,1684),(0.0252004,1682),(0.0255529,1680),(0.0256147,1665),(0.0256615,1662),(0.0258708,1656),(0.0261672,1655),(0.0265897,1641),(0.0277627,1636),(0.0281267,1630),(0.0295473,1627),(0.0316662,1619),(0.0317112,1609),(0.0321168,1608),(0.0327812,1607),(0.032942,1599),(0.0330804,1596),(0.0332796,1584),(0.0334116,1563),(0.0337158,1562),(0.0339262,1560),(0.0345383,1555),(0.0349999,1554),(0.0359406,1545),(0.0359874,1536),(0.0367203,1534),(0.03749,1530),(0.0396946,1529),(0.0402544,1528),(0.0409461,1521),(0.0418377,1520),(0.0441215,1519),(0.0450143,1518),(0.04585,1517),(0.0469667,1514),(0.0470257,1513),(0.0472574,1512),(0.0490133,1511),(0.0493389,1506),(0.0496283,1502),(0.0497766,1501),(0.0503079,1499),(0.0522218,1495),(0.052793,1492),(0.0584095,1491),(0.0585844,1488),(0.0587572,1487),(0.0590803,1486),(0.0598163,1477),(0.0617489,1476),(0.0633742,1466),(0.0653163,1462),(0.0665628,1461),(0.0675813,1460),(0.0686884,1457),(0.0689813,1455),(0.0698387,1449),(0.0703194,1447),(0.0717419,1446),(0.0733168,1445),(0.0815223,1444),(0.085663,1438),(0.0887571,1437),(0.0904036,1434),(0.0970168,1432),(0.0988157,1431),(0.0990529,1420),(0.1009,1417),(0.103466,1412),(0.112686,1411),(0.113094,1410),(0.122084,1409),(0.122253,1408),(0.12319,1407),(0.124722,1403),(0.135268,1392),(0.141893,1391),(0.143065,1386),(0.14565,1385),(0.147049,1380),(0.149755,1378),(0.151998,1376),(0.157567,1375),(0.158628,1367),(0.161414,1366),(0.164501,1365),(0.172883,1364),(0.188404,1363),(0.190183,1361),(0.191266,1360),(0.195809,1354),(0.196557,1353),(0.199603,1351),(0.207277,1345),(0.211084,1344),(0.213451,1338),(0.230689,1334),(0.238889,1333),(0.248361,1330),(0.255012,1328),(0.260965,1327),(0.26336,1319),(0.26555,1318),(0.289249,1316),(0.344983,1314),(0.351626,1312),(0.362535,1305),(0.371573,1304),(0.372683,1303),(0.383441,1299),(0.408047,1298),(0.43332,1296),(0.439339,1295),(0.457302,1294),(0.523847,1293),(0.527816,1290),(0.539777,1289),(0.557334,1288),(0.558559,1287),(0.689586,1283),(0.699086,1276),(0.743403,1274),(0.754213,1272),(0.795653,1271),(0.970297,1270),(1.0449,1267),(1.05622,1262),(1.06138,1259),(1.10266,1258),(1.20857,1253),(1.70267,1252),(1.9899,1251),(2.6867,1246),(2.71625,1245),(3.49626,1244),(3.53134,1243),(3.59241,1242),(3.7559,1241),(4.04877,1240),(4.07925,1238),(4.10536,1237),(4.15855,1232),(4.18016,1231),(4.3346,1230),(4.36283,1229),(4.45756,1228),(5.83927,1219),(5.9492,1218),(7.08796,1215),(7.23433,1213),(11.0353,1212),(26.6222,1209),(26.6987,1206),(84.211,1204),(107.607,1203),(108.472,1201),(108.63,1200),(108.721,1197),(108.811,1195),(360, 1195)]",
    "[(0,1812),(0.148498,1810),(0.14854,1807),(0.148652,1805),(0.148822,1802),(0.149066,1793),(0.149075,1792),(0.149714,1789),(0.149972,1786),(0.150047,1781),(0.150189,1779),(0.15027,1777),(0.150711,1775),(0.150911,1772),(0.150935,1770),(0.150946,1766),(0.151098,1765),(0.151311,1764),(0.151369,1760),(0.151889,1749),(0.152177,1739),(0.153215,1738),(0.153325,1737),(0.153806,1736),(0.153956,1735),(0.153965,1734),(0.154423,1725),(0.155039,1722),(0.155128,1721),(0.155677,1720),(0.156431,1719),(0.15688,1714),(0.157438,1713),(0.15864,1710),(0.159102,1701),(0.159241,1700),(0.15962,1696),(0.16047,1690),(0.160556,1688),(0.161255,1686),(0.161341,1685),(0.161441,1684),(0.162008,1683),(0.163713,1681),(0.163976,1673),(0.164613,1672),(0.165229,1662),(0.165493,1659),(0.167016,1658),(0.167076,1650),(0.167259,1648),(0.16759,1647),(0.167753,1646),(0.168701,1636),(0.168792,1632),(0.169832,1623),(0.169867,1622),(0.170094,1618),(0.170748,1617),(0.170937,1614),(0.17206,1612),(0.174044,1611),(0.175158,1609),(0.175665,1608),(0.177671,1604),(0.178041,1602),(0.180079,1601),(0.180231,1599),(0.180726,1598),(0.181034,1588),(0.181368,1587),(0.181868,1582),(0.181909,1578),(0.182336,1577),(0.183692,1572),(0.184625,1571),(0.185253,1563),(0.186364,1562),(0.186396,1560),(0.186425,1559),(0.187967,1551),(0.188956,1543),(0.189019,1542),(0.190787,1541),(0.190874,1537),(0.19165,1536),(0.192996,1528),(0.193257,1527),(0.194198,1523),(0.194488,1521),(0.19451,1519),(0.195141,1509),(0.197919,1508),(0.198009,1500),(0.198485,1498),(0.210102,1492),(0.211342,1491),(0.211481,1488),(0.211525,1485),(0.215202,1483),(0.216905,1478),(0.217028,1477),(0.2263,1475),(0.232791,1473),(0.237882,1472),(0.240647,1471),(0.240747,1469),(0.240769,1468),(0.24303,1463),(0.243566,1460),(0.245091,1451),(0.248888,1450),(0.248957,1448),(0.254967,1447),(0.257779,1443),(0.259012,1436),(0.260107,1434),(0.261276,1423),(0.261592,1422),(0.268954,1417),(0.271502,1416),(0.273389,1415),(0.274788,1404),(0.274976,1403),(0.279367,1402),(0.27993,1395),(0.280741,1394),(0.284955,1384),(0.289897,1383),(0.291543,1382),(0.292175,1375),(0.295218,1374),(0.303642,1370),(0.305626,1369),(0.312534,1364),(0.319484,1363),(0.324457,1361),(0.325022,1359),(0.344739,1352),(0.350113,1351),(0.355092,1345),(0.359435,1341),(0.424851,1338),(0.441797,1334),(0.455085,1331),(0.471885,1330),(0.473876,1325),(0.48826,1317),(0.490028,1311),(0.507981,1305),(0.525853,1296),(0.541363,1295),(0.545387,1292),(0.598978,1290),(0.654453,1289),(0.688555,1287),(0.746424,1286),(0.761996,1285),(0.806686,1284),(0.823868,1283),(0.925547,1282),(0.946261,1281),(0.972173,1280),(0.977232,1279),(1.06071,1271),(1.07525,1267),(1.09792,1261),(1.12599,1260),(1.15351,1252),(1.2545,1247),(1.26765,1245),(1.42848,1239),(1.62742,1238),(1.65512,1236),(1.68652,1235),(1.78764,1231),(1.80352,1230),(1.86527,1229),(1.92627,1228),(2.17328,1227),(2.78532,1226),(2.89216,1225),(3.30626,1221),(3.8375,1220),(4.02106,1218),(4.04131,1214),(4.10413,1213),(4.46743,1211),(6.85668,1207),(10.3156,1206),(12.9888,1205),(16.6285,1203),(16.9897,1202),(17.5863,1201),(17.6164,1199),(17.9183,1198),(18.1834,1192),(18.5139,1191),(360, 1195)]"
]
# The provided string representations of the lists of tuples

# Convert the string representations to lists of tuples
data_lists = [eval(data_string) for data_string in data_strings]

# Modify the second value of each tuple using the calculate_error function
for neighbour in data_lists:
    for i in range(len(neighbour)):
        first, second = neighbour[i]
        modified_second = calculate_error(second)
        neighbour[i] = (first, modified_second)

print(data_lists)

max_length = max(len(lst) for lst in data_lists)

# Writing the data to a CSV file
csv_file_path = 'rbg358_sa.csv'
with open(csv_file_path, 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)

    # Iterate up to the length of the longest list
    for i in range(max_length):
        row = []
        # Gather ith element from each list, or use placeholders if the list is shorter
        for lst in data_lists:
            if i < len(lst):
                row.extend(lst[i])
            else:
                row.extend(["", ""])  # Using empty strings as placeholders
        writer.writerow(row)
