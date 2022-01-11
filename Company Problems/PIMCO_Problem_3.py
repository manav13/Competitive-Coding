import copy

def compFunc(bidder):
    return bidder[3]

def getUnallottedUsers(bids, totalShares):
    bCopy = copy.deepcopy(bids)
    prices = [bid[2] for bid in bids if bid[1] > 0]
    
    while(len(prices) > 0 and totalShares > 0):
        maximumPrice = max(prices)
        maxBidderCount = prices.count(maximumPrice)
        
        prices = [p for p in prices if p!=maximumPrice]
        if(maxBidderCount == 1):
            for bidder in bids:
                if(bidder[2] == maximumPrice):
                    if(totalShares >= bidder[1]):
                        totalShares -= bidder[1]
                        bidder[1] = 0
                    else:
                        bidder[1] -= totalShares
                        totalShares = 0
                    
        else:
            maxBidder = []
            for bidder in bids:
                if(bidder[2] == maximumPrice):
                    maxBidder.append(bidder)
            maxBidder.sort(key=compFunc)
            alloc = 0
            
            while (totalShares > 0 and alloc != len(maxBidder)):
                for bidder in maxBidder:
                    if(bidder[1] == 1 and totalShares > 0):
                        bidder[1] -= 1
                        totalShares -= 1
                        alloc += 1
                    elif(bidder[1] > 0 and totalShares > 0):
                        bidder[1] -= 1
                        totalShares -= 1
        
    unalloc = []
    for bidder in bids:
        for bidder_copy in bCopy:
            if(bidder[0] == bidder_copy[0] and bidder[1] == bidder_copy[1]):
                unalloc.append(bidder[0])
                break
    return unalloc