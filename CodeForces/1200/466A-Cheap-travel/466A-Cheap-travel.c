#include "466A-Cheap-travel.h"
#include <stdio.h>
#include <stdlib.h>

int travelCost(int rides, int multiTicketRides, int singleTicketPrice,
               int multiTicketPrice) {

  // buying only multiTickets
  int multiTicketsNeeded = (rides + multiTicketRides - 1) / multiTicketRides;
  int totalMultiTicketsCost = multiTicketsNeeded * multiTicketPrice;

  // buying multiTickets and fill out wiht singleTicket
  int partMultiTicketsNeeded = rides / multiTicketRides;
  int ridesCovered = partMultiTicketsNeeded * multiTicketRides;
  int partSinglesNeeded = rides - ridesCovered;
  int totalPartTicketsCost = partMultiTicketsNeeded * multiTicketPrice +
                             partSinglesNeeded * singleTicketPrice;

  // buy only singleTickets
  int totalSingleTicketsCost = rides * singleTicketPrice;

  int answer = totalMultiTicketsCost;
  answer = answer < totalPartTicketsCost ? answer : totalPartTicketsCost;
  answer = answer < totalSingleTicketsCost ? answer : totalSingleTicketsCost;

  return answer;
}