#coding:utf8
'''
Created on 2011-10-14

@author: lan
'''
from twisted.spread import pb
from firefly.utils.services import Service


class ProxyReference(pb.Referenceable):
    '''代理通道'''
    
    def __init__(self):
        '''初始化'''
        pb.Referenceable()
        self._service = Service('proxy')
        
    def addService(self,service):
        '''添加一条服务通道'''
        self._service = service
    
    def remote_callChild(self, command,*arg,**kw):
        '''代理发送数据
        '''
        return self._service.callTarget(command,*arg,**kw)
    
    
    
        