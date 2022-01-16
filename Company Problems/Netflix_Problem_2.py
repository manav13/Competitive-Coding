# Underground Subway stations

if origin not in stationsA and origin not in stationsB and origin not in stationsC:
    return ''
elif destination not in stationsA and destination not in stationsB and destination not in stationsC:
    return ''
elif origin in stationsA and destination in stationsA:
    return "AB'
elif origin in stationsA and destination in stationsB:
    return 'AB'
elif origin in stationsA and destination in stationsC:
    return 'ABC'
elif origin in stationsB and destination in stationsA:
    return 'AB'
elif origin in stationsB and destination in stationsB:
    return 'AB'
elif origin in stationsB and destination in stationsC:
    return 'BC'
elif origin in stationsC and destination in stationsA:
    return 'ABC'
elif origin in stationsC and destination in stationsB:
    return 'BC'
elif origin in stationsC and destination in stationsC:
    return "BC'