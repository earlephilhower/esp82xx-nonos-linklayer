#ifndef __ESPCONN_TCP_H__
#define __ESPCONN_TCP_H__

#ifndef ESPCONN_TCP_DEBUG
#define ESPCONN_TCP_DEBUG LWIP_DBG_OFF
#endif
#include "lwip/apps-esp/espconn.h"

#ifndef ESPCONN_TCP_TIMER
#define ESPCONN_TCP_TIMER 40
#endif

#define  espconn_keepalive_enable(pcb)   ((pcb)->so_options |= SOF_KEEPALIVE)
#define  espconn_keepalive_disable(pcb)   ((pcb)->so_options &= ~SOF_KEEPALIVE)

#define   espconn_manual_recv_disabled(espconn)  (((espconn)->pcommon.espconn_opt & ESPCONN_MANUALRECV) != 0)
#define   espconn_manual_recv_enabled(espconn)  (((espconn)->pcommon.espconn_opt & ESPCONN_MANUALRECV) == 0)

/******************************************************************************
 * FunctionName : espconn_kill_oldest_pcb
 * Description  : A oldest incoming connection has been killed.
 * Parameters   : none
 * Returns      : none
*******************************************************************************/

extern void espconn_kill_oldest_pcb(void);

/******************************************************************************
 * FunctionName : espconn_tcp_disconnect
 * Description  : A new incoming connection has been disconnected.
 * Parameters   : espconn -- the espconn used to disconnect with host
 * Returns      : none
*******************************************************************************/

extern void espconn_tcp_disconnect(espconn_msg *pdiscon,u8 type);

/******************************************************************************
 * FunctionName : espconn_tcp_client
 * Description  : Initialize the client: set up a connect PCB and bind it to 
 *                the defined port
 * Parameters   : espconn -- the espconn used to build client
 * Returns      : none
*******************************************************************************/

extern sint8 espconn_tcp_client(struct espconn* espconn);

/******************************************************************************
 * FunctionName : espconn_tcp_server
 * Description  : Initialize the server: set up a listening PCB and bind it to 
 *                the defined port
 * Parameters   : espconn -- the espconn used to build server
 * Returns      : none
*******************************************************************************/

extern sint8 espconn_tcp_server(struct espconn *espconn);

// added for warning-less compilation:

err_t ICACHE_FLASH_ATTR espconn_tcp_write(void *arg);
sint8 ICACHE_FLASH_ATTR espconn_recv_unhold(struct espconn *pespconn);
sint8 ICACHE_FLASH_ATTR espconn_tcp_delete(struct espconn *pdeletecon);

#endif /* __CLIENT_TCP_H__ */

